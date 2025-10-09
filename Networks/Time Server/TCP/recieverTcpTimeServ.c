#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 3969
#define LOCALHOST inet_addr("127.0.0.1")
#define BUFFER_SIZE 256

void error_check(int s, char msg[]){
    if (s<0){
        perror("Failed");
        exit(0);
    } else {
        printf("%s\n", msg);
    }
}

void main(){
    //define variables
    int sock;
    struct sockaddr_in serveraddr, clientaddr;
    char buffer[BUFFER_SIZE];

    //create socket
    sock=socket(AF_INET, SOCK_STREAM, 0);
    error_check(sock, "Socket created");

    //bind socket
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=LOCALHOST;
    int b= bind(sock, (struct sockaddr*) & serveraddr, sizeof(serveraddr));
    error_check(b, "Binding done");     

    //listen
    int l=listen(sock, 5);
    error_check(l, "Listening.....");

    //accept connection
    socklen_t clen= sizeof(clientaddr);
    int newsock=accept(sock, ( struct sockaddr*)&clientaddr, &clen);
    error_check(newsock, "Connection accepted");

    //operations
    while(1){
        int status=-1;
        time_t t=time(NULL);
        char *msg = ctime(&t);

        status=recv(newsock, buffer, BUFFER_SIZE, 0);
        error_check(status, "Message received");
        printf("Client: %s\n", buffer);

        status=send(newsock, msg, strlen(msg), 0);
        error_check(status, "Reply sent");

        exit(0);
    }

    close(sock);
    close(newsock);
}