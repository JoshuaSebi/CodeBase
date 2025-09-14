#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080
#define MAX_FRAME_SIZE 1024
#define TIMEOUT_SEC 2
#define MAX_FRAMES 10
#define WINDOW_SIZE 3

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
    struct sockaddr_in servaddr;
    Frame frames_to_send[MAX_FRAMES + 1];
    Ack ack;
    socklen_t len = sizeof(servaddr);
    fd_set fds;
    struct timeval tv;

    int base = 1;
    int next_seq_num = 1;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        die("socket creation failed");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    for (int i = 1; i <= MAX_FRAMES; i++) {
        frames_to_send[i].frame_no = i;
        snprintf(frames_to_send[i].data, MAX_FRAME_SIZE, "Frame %d data", i);
    }

    while (base <= MAX_FRAMES) {
        while (next_seq_num < base + WINDOW_SIZE && next_seq_num <= MAX_FRAMES) {
            sendto(sockfd, &frames_to_send[next_seq_num], sizeof(Frame), 0, (const struct sockaddr *)&servaddr, len);
            printf("Sender: Sent frame %d\n", next_seq_num);
            next_seq_num++;
        }

        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);
        tv.tv_sec = TIMEOUT_SEC;
        tv.tv_usec = 0;

        int ready = select(sockfd + 1, &fds, NULL, NULL, &tv);

        if (ready < 0) {
            die("select error");
        } else if (ready == 0) {
            printf("Sender: >>> Timeout for ACK of frame %d. Going back to resend window. <<<\n", base);
            next_seq_num = base; 
        } else {
            recvfrom(sockfd, &ack, sizeof(ack), 0, (struct sockaddr *)&servaddr, &len);
            printf("Sender: Received ACK %d\n", ack.ack_no);

            if (ack.ack_no >= base) {
                base = ack.ack_no + 1;
                printf("Sender: Window base is now %d\n", base);
            }
        }
    }

    close(sockfd);
    printf("Sender: All frames sent and acknowledged successfully.\n");
    return 0;
}