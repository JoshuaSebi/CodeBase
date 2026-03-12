#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1828
#define LOCALHOST inet_addr("127.0.0.1")
#define WIN 3
#define TOTAL 6

typedef struct {
    int fnum;
    char data[30];
} Frame;

typedef struct {
    int anum;
} Ack;

int main() {
    int sock;
    struct sockaddr_in serveraddr, clientaddr;
    Frame f;
    Ack a;
    socklen_t len = sizeof(clientaddr);
    int received[TOTAL + 1] = {0};
    int drop3 = 0;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = LOCALHOST;

    bind(sock, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    printf("[SERVER] Selective Repeat ARQ Started\n");

    while (1) {
        int r = recvfrom(sock, &f, sizeof(f), 0, (struct sockaddr*)&clientaddr, &len);
        if (r < 0) continue;

        printf("[SERVER] Frame %d received: %s\n", f.fnum, f.data);

        // Simulate ACK loss for frame 3 once
        if (f.fnum == 3 && drop3 == 0) {
            printf("[SERVER] Dropping ACK for Frame 3\n");
            drop3 = 1;
            continue;
        }

        // Mark frame as received
        if (f.fnum >= 1 && f.fnum <= TOTAL) received[f.fnum] = 1;

        // Send individual ACK
        a.anum = f.fnum;
        sendto(sock, &a, sizeof(a), 0, (struct sockaddr*)&clientaddr, len);
        printf("[SERVER] ACK %d sent\n", a.anum);

        // Stop when all received
        int all = 1;
        for (int i = 1; i <= TOTAL; i++) {
            if (!received[i]) { all = 0; break; }
        }
        if (all) break;
    }

    printf("[SERVER] All frames received!\n");
    close(sock);
    return 0;
}
