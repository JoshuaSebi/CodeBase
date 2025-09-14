#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_FRAME_SIZE 1024
#define MAX_FRAMES 10

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
    int expected_frame_no = 1;
    
    // Flag to ensure we only drop the ACK once
    int dropped_ack_4 = 0;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        die("socket creation failed");
    }

    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        die("setsockopt failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        die("bind failed");
    }

    printf("Receiver is ready and waiting...\n");

    while (expected_frame_no <= MAX_FRAMES) {
        recvfrom(sockfd, &frame, sizeof(frame), 0, (struct sockaddr *)&cliaddr, &len);
        printf("Receiver: Got frame #%d, expecting #%d\n", frame.frame_no, expected_frame_no);

        // --- SIMULATE DROPPED ACK FOR FRAME 4 ---
        if (frame.frame_no == 4 && !dropped_ack_4) {
            printf("Receiver: <<< Intentionally dropping ACK for frame 4 >>>\n");
            dropped_ack_4 = 1;
            // Skip sending the ACK this one time
            continue; 
        }
        // -----------------------------------------

        if (frame.frame_no == expected_frame_no) {
            printf("Receiver: Frame %d accepted. Data: '%s'\n", frame.frame_no, frame.data);
            ack.ack_no = expected_frame_no;
            sendto(sockfd, &ack, sizeof(ack), 0, (const struct sockaddr *)&cliaddr, len);
            printf("Receiver: Sent ACK for frame %d\n", ack.ack_no);
            expected_frame_no++;
        } else {
            printf("Receiver: Frame %d is out of order, discarding.\n", frame.frame_no);
            ack.ack_no = expected_frame_no - 1;
            sendto(sockfd, &ack, sizeof(ack), 0, (const struct sockaddr *)&cliaddr, len);
            printf("Receiver: Re-sent ACK for frame %d\n", ack.ack_no);
        }
    }

    close(sockfd);
    printf("Receiver: All frames received successfully.\n");
    return 0;
}