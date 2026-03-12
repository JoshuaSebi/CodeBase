#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 1243
#define MAXSIZE 128
#define LOCALHOST inet_addr("127.0.0.1")

typedef struct {
    int frame_no;
    char data[30];
} Frame;

typedef struct {
    int ack_no;
} Ack;

void main(){
    Frame f;
    Ack a;
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t len = sizeof(client_addr);
    sockfd = socket(AF_INET, SOCK_DGRAM,0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr=LOCALHOST;
    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    int seq=1;
    int dropped3=0;
    while(seq<=6){
        //recieve frame
        recvfrom(sockfd, &f, (sizeof(f)), 0, (struct sockaddr*)&client_addr, &len);
        printf("[Server] Frame %d received\n",f.frame_no);

        if(rand()%100<40){
            printf("[Server] Frame %d dropped\n",f.frame_no);
            continue;
        }

        //send ack
        if (f.frame_no==seq){
            a.ack_no=f.frame_no;
            sendto(sockfd, &a, sizeof(a), 0, (struct sockaddr*)&client_addr, len);
            printf("[Server] ACK %d sent\n",a.ack_no);
            seq++;
        } else {
            // Resend ACK for last received in-order frame
            a.ack_no=seq-1;
            sendto(sockfd, &a, sizeof(a), 0, (struct sockaddr*)&client_addr, len);
            printf("[Server] ACK %d resent\n",a.ack_no);
        }    
    }
    close(sockfd);
}