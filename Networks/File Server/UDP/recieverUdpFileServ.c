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

void main(){
    //define variables
    int sock;
    struct sockaddr_in clientaddr, serveraddr;
    char buffer[BUFFER_SIZE]; 

    //create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    error_check(sock, "Socket created successfully");

    //bind socket to port
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = LOCALHOST;
    int b= bind(sock, (struct sockaddr*) &serveraddr, sizeof(serveraddr));
    error_check(b, "Socket binded to port successfully");

    while(1){
        int fd;
        socklen_t clen=sizeof(clientaddr);

        //recieve filename
        int s=recvfrom(sock, buffer, BUFFER_SIZE-1, 0, (struct sockaddr*) &clientaddr, &clen);
        error_check(s, "Filename received");
        buffer[strcspn(buffer,"\n")]=0;

        //open file
        fd=open(buffer, O_RDONLY);
        if (fd<0){
            char msg[]="File not found";
            sendto(sock, msg, strlen(msg), 0, (struct sockaddr*) &clientaddr, clen);
            printf("File not found\n");
        } else {
            int n;
            while((n=read(fd,buffer, BUFFER_SIZE-1))>0){
                buffer[n]='\0';
                sendto(sock, buffer, n, 0, (struct sockaddr*) &clientaddr, clen);
                memset(buffer, 0, BUFFER_SIZE);
            }
            close(fd);
            printf("File sent successfully\n");
        }
    }
    close(sock);
}