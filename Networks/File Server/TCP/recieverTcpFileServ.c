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

void main(){
    //define variables
    int sock;
    struct sockaddr_in clientaddr, serveraddr;
    char buffer[BUFFER_SIZE]; 

    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    error_check(sock, "Socket created successfully");

    //bind socket to port
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr.s_addr = LOCALHOST;
    int b= bind(sock, (struct sockaddr*) &serveraddr, sizeof(serveraddr));
    error_check(b, "Socket binded to port successfully");

    //listen
    int l=listen(sock, 5);
    error_check(l, "Listening....");

    while(1){
        //accept conn
        socklen_t clen=sizeof(clientaddr);
        int newsock=accept(sock, (struct sockaddr*)&clientaddr, &clen);
        error_check(newsock, "Connection Established");
        //=====================================================
        int status=recv(newsock, buffer, BUFFER_SIZE-1, 0);
        error_check(status, "Recieved File Name");
        buffer[strcspn(buffer,"\n")]=0;
        printf("%s\n",buffer);

        char msg[BUFFER_SIZE];
        int fd=open(buffer, O_RDONLY);
        if (fd<0){
            snprintf(msg,sizeof(msg),"Error finding file\nPID: %d\n",getpid());
            send(newsock, msg, strlen(msg),0);
            printf("Error");
            continue;
        } else {
            snprintf(msg,sizeof(msg),"file found\nPID: %d\n",getpid());
            printf("Found");
            int n;
            while((n=read(fd, buffer, BUFFER_SIZE-1))>0){
                buffer[n]='\0';
                send(newsock, buffer, n, 0);
                memset(buffer,0,BUFFER_SIZE);
            }
            close(fd);
        }
        close(newsock);
    }
    close(sock);
}