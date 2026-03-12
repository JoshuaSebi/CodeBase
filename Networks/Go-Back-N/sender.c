#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define PORT 1243
#define MAXSIZE 128
#define LOCALHOST inet_addr("127.0.0.1")
#define WINSIZE 3

typedef struct {
    int fnum;
    char data[30];
} Frame;

typedef struct {
    int anum;
} Ack;

void main(){
    Frame f;
    Ack a;
    int sock;
    struct sockaddr_in serveraddr;
    socklen_t len=sizeof(serveraddr);
    sock = socket(AF_INET, SOCK_DGRAM, 0);

    // Set socket timeout to 3 seconds
    struct timeval timeout={3,0};
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=LOCALHOST;

    int base=1;
    int nextseqnum=1;

    while (base<=6){
        //send frames in window
        while(nextseqnum<=WINSIZE+base-1 && nextseqnum<=6){
            f.fnum=nextseqnum;
            sprintf(f.data,"This is Frame %d\n",nextseqnum);
            sendto(sock, &f, sizeof(f),0,(struct sockaddr*)&serveraddr, sizeof(serveraddr));
            printf("[Client] Frame %d sent\n",nextseqnum);
            nextseqnum++;
        }

        //Wait for ack  
        recvfrom(sock, &a, sizeof(a),0, (struct sockaddr*)&serveraddr, &len);
        if (a.anum>=base){
            printf("[Client] ACK %d received\n",a.anum);
            base=a.anum+1; 
        }
        else{
            printf("[Client] ACK not recieved, resesnding frames from %d to %d\n",base,nextseqnum-1);
            nextseqnum=base;
        }
        sleep(1);
    }
}
