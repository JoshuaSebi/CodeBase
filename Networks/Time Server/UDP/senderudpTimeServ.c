#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5111
#define BUFFER_SIZE 256
#define LOCALHOST inet_addr("127.0.0.1")

void error_check(int s, char msg[]){
    if (s<0){
        perror("Failed");
        exit(0);
    } else {
        printf("%s\n", msg);
    }
}

void main(){
    //define local variables
    int sock;
    struct sockaddr_in clientaddr;
    char buffer[BUFFER_SIZE];

    //create socket
    sock= socket(AF_INET, SOCK_DGRAM, 0);
    error_check(sock, "Socket Created");

    ////define client address
    clientaddr.sin_family=AF_INET;
    clientaddr.sin_port=htons(PORT);
    clientaddr.sin_addr.s_addr=LOCALHOST;

    //operations
    int status=-1;
    char msg[]="Current Time?";
    status=sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
    error_check(status, "Message Sent");

    socklen_t clen= sizeof(clientaddr);
    status=recvfrom(sock, buffer, sizeof(buffer)-1, 0, (struct sockaddr*) &clientaddr, &clen);
    error_check(status, "Reply Received");
    printf("Server: %s\n", buffer);

    //close
    close(sock); 
}


