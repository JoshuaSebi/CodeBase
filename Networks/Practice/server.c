#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define PORT 8080
#define MAX_FRAMES 10
#define LOST_FRAME_NO 3

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len = sizeof(cliaddr);
    char buffer[1024];
    bool received[MAX_FRAMES] = {false};
    bool lost_done = false;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Server ready. Waiting for frames...\n");

    int delivered_upto = 0;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        if (n <= 0)
            continue;

        if (strncmp(buffer, "END", 3) == 0) {
            printf("Transmission complete.\n");
            break;
        }

        int frame_no = atoi(buffer);
        printf("\n[SERVER] Frame %d received\n", frame_no);

        if (!lost_done && frame_no == LOST_FRAME_NO) {
            printf("   >> Simulating loss of frame %d\n", frame_no);
            lost_done = true;
            continue;
        }

        received[frame_no] = true;
        printf("   Frame %d stored in buffer\n", frame_no);

        // Send ACK for this frame
        char ack_msg[16];
        sprintf(ack_msg, "ACK%d", frame_no);
        sendto(sockfd, ack_msg, strlen(ack_msg) + 1, 0, (struct sockaddr *)&cliaddr, len);
        printf("   Sent %s\n", ack_msg);

        // Deliver frames in order
        while (delivered_upto < MAX_FRAMES && received[delivered_upto]) {
            printf("   Delivered frame %d to application\n", delivered_upto);
            delivered_upto++;
        }
    }

    close(sockfd);
    return 0;
}
