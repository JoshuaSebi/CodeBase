#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>

#define PORT 8080
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
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    error_check(sock, "Socket created successfully");

    //client address
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_port = htons(PORT);
    clientaddr.sin_addr.s_addr = LOCALHOST;
    socklen_t clen = sizeof(clientaddr);

    char filename[BUFFER_SIZE];
    printf("Enter File Name: ");
    fgets(filename, sizeof(filename), stdin);

    //send filename to server
    int status=sendto(sock, filename, strlen(filename),0, (struct sockaddr*) &clientaddr, clen);
    error_check(status, "Filename sent");

    //receive file content from server
    while(recvfrom(sock, buffer, BUFFER_SIZE-1, 0, (struct sockaddr*) &clientaddr, &clen) > 0){
        buffer[BUFFER_SIZE-1]='\0';
        printf("%s\n",buffer);
        memset(buffer, 0, BUFFER_SIZE);
    }

    //close
    close(sock);
}