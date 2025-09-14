#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_FRAME_SIZE 1024
#define MAX_FRAMES 6

typedef struct {
    int frame_no;
    char data[MAX_FRAME_SIZE];
} Frame;

typedef struct {
    int ack_no;
} Ack;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    Frame frame;
    Ack ack;
    socklen_t len = sizeof(cliaddr);
    int expected_frame = 1;

    // Track dropped frames 3 and 5
    int dropped3 = 0, dropped5 = 0;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        die("socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        die("bind failed");
    }
    
    printf("Receiver is ready and waiting...\n");

    while (expected_frame <= MAX_FRAMES) {
        recvfrom(sockfd, &frame, sizeof(frame), 0, (struct sockaddr *)&cliaddr, &len);
        printf("Receiver: Got frame #%d, data='%s'\n", frame.frame_no, frame.data);

        // Drop frame 3 once
        if (frame.frame_no == 3 && !dropped3) {
            printf("Receiver: Intentionally dropping ACK for frame 3\n");
            dropped3 = 1;
            continue;
        }

        // Drop frame 5 once
        if (frame.frame_no == 5 && !dropped5) {
            printf("Receiver: Intentionally dropping ACK for frame 5\n");
            dropped5 = 1;
            continue;
        }

        if (frame.frame_no == expected_frame) {
            printf("Receiver: Delivered data: %s\n", frame.data);
            expected_frame++;
        } else {
            printf("Receiver: Out of order frame %d (expected %d), ignoring\n",
                   frame.frame_no, expected_frame);
        }

        ack.ack_no = frame.frame_no;
        sendto(sockfd, &ack, sizeof(ack), 0, (const struct sockaddr *)&cliaddr, len);
        printf("Receiver: Sent ACK for frame %d\n", frame.frame_no);
    }

    close(sockfd);
    printf("Receiver: All frames received successfully\n");
    return 0;
}