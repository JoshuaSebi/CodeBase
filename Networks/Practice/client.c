#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define PORT 8080
#define MAX_FRAMES 10
#define WINDOW_SIZE 4
#define TIMEOUT 3

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    socklen_t len = sizeof(servaddr);
    char buffer[1024];
    bool acked[MAX_FRAMES] = {false};

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    struct timeval tv = {TIMEOUT, 0};
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    printf("Client ready to send frames...\n");

    int base = 0, next = 0;
    int timers[MAX_FRAMES] = {0};

    while (base < MAX_FRAMES) {
        // Send frames in window
        while (next < base + WINDOW_SIZE && next < MAX_FRAMES) {
            char msg[16];
            sprintf(msg, "%d", next);
            sendto(sockfd, msg, strlen(msg) + 1, 0, (struct sockaddr *)&servaddr, len);
            printf("[CLIENT] Sent Frame %d\n", next);
            timers[next] = 0;
            next++;
        }

        // Wait for ACK
        memset(buffer, 0, sizeof(buffer));
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&servaddr, &len);

        if (n > 0) {
            int ack_no = atoi(buffer + 3);
            printf("[CLIENT] Received %s\n", buffer);
            acked[ack_no] = true;
        } else {
            // Handle timeouts
            for (int i = base; i < next; i++) {
                if (!acked[i]) {
                    timers[i]++;
                    if (timers[i] >= TIMEOUT) {
                        char msg[16];
                        sprintf(msg, "%d", i);
                        sendto(sockfd, msg, strlen(msg) + 1, 0, (struct sockaddr *)&servaddr, len);
                        printf("[CLIENT] Timeout! Retransmitting Frame %d\n", i);
                        timers[i] = 0;
                    }
                }
            }
        }

        // Slide window
        while (base < MAX_FRAMES && acked[base])
            base++;
    }

    sendto(sockfd, "END", strlen("END") + 1, 0, (struct sockaddr *)&servaddr, len);
    printf("All frames sent successfully.\n");

    close(sockfd);
    return 0;
}
