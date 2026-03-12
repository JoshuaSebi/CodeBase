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
    struct sockaddr_in serveraddr;
    Frame f;
    Ack a;
    socklen_t len = sizeof(serveraddr);
    int base = 1, nextseq = 1;
    int acked[TOTAL + 1] = {0};

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct timeval tv = {3, 0};
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = LOCALHOST;

    printf("[CLIENT] Selective Repeat ARQ Started\n");

    while (base <= TOTAL) {
        // Send frames in window that are not yet acked
        for (int i = base; i < base + WIN && i <= TOTAL; i++) {
            if (!acked[i]) {
                f.fnum = i;
                sprintf(f.data, "This is Frame %d", f.fnum);
                sendto(sock, &f, sizeof(f), 0, (struct sockaddr*)&serveraddr, len);
                printf("[CLIENT] Frame %d sent\n", f.fnum);
            }
        }

        // Wait for ACK
        int n = recvfrom(sock, &a, sizeof(a), 0, (struct sockaddr*)&serveraddr, &len);
        if (n < 0) {
            printf("[CLIENT] Timeout! Resending unacknowledged frames...\n");
            continue;
        }

        // Mark ACK received
        if (a.anum >= 1 && a.anum <= TOTAL) {
            if (!acked[a.anum]) {
                acked[a.anum] = 1;
                printf("[CLIENT] ACK %d received\n", a.anum);
            }
        }

        // Slide window base
        while (acked[base] && base <= TOTAL) base++;
    }

    printf("[CLIENT] All frames sent and acknowledged!\n");
    close(sock);
    return 0;
}
