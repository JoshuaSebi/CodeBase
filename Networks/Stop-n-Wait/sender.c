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

    for (int i=1; i<=6; i++){
        f.fnum=i;
        sprintf(f.data,"This is Frame %d\n",i);

        while(1){
            sendto(sock, &f, sizeof(f),0,(struct sockaddr*)&serveraddr, sizeof(serveraddr));
            printf("[Client] Frame %d sent\n",i);

            //Wait for ack
            recvfrom(sock, &a, sizeof(a),0, (struct sockaddr*)&serveraddr, &len);
            if(a.anum==i){
                printf("[Client] ACK %d received\n",a.anum);
                break;
            }
            else{
                printf("[Client] ACK not recieved, resesnd Frame %d\n",i);
            }
        }
        sleep(1);
    }
    close(sock);
}
