#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>

#define PORT 3700
#define LOCALHOST inet_addr("127.0.0.1")
#define BUFFER_SIZE 1024

void error_check(int s, char msg[]){
    if(s < 0){
        perror("Failed");
        exit(0);
    } else {
        printf("%s\n", msg);
    }
}

void main() {
    //define variables
    int sock;
    struct sockaddr_in clientaddr;
    char buffer[BUFFER_SIZE]; 

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    error_check(sock, "Socket created successfully");

    //connect
    clientaddr.sin_family=AF_INET;
    clientaddr.sin_port=htons(PORT);
    clientaddr.sin_addr.s_addr=LOCALHOST;
    socklen_t clen= sizeof(clientaddr);

    //connect
    int c=connect(sock, (struct sockaddr*) &clientaddr, clen);
    error_check(c, "Connected to the server");

    //perform operations
    char msg[BUFFER_SIZE];

    printf("Enter File Name: ");
    fgets(msg, sizeof(msg), stdin);
    int status=send(sock,msg,strlen(msg),0);

    while(recv(sock, buffer, BUFFER_SIZE-1,0)>0){
        buffer[BUFFER_SIZE-1]='\0';
        printf("%s\n",buffer);
        memset(buffer,0,BUFFER_SIZE);
    }
    close(sock);
}