#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
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
    }
    else{
        printf("\n%s\n",msg);
    }
}

void main(){
    //define local variables
    int sock;
    struct sockaddr_in clientaddr, serveraddr;
    char buffer[BUFFER_SIZE];

    //create socket
    sock= socket(AF_INET, SOCK_DGRAM, 0);
    error_check(sock, "Socket Created");

    //bind server address
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(PORT);
    serveraddr.sin_addr.s_addr=LOCALHOST;
    int b= bind(sock, (struct sockaddr *) &serveraddr, sizeof(serveraddr));
    error_check(b, "Binding Done");

    //operations (send current time)
    int status=-1;
    time_t t=time(NULL);
    char *msg = ctime(&t);
    int clen = sizeof(clientaddr);

    status=recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*) &clientaddr, &clen);
    error_check(status, "Message Recieved");    
    printf("Client: %s\n", buffer);
    status=sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
    error_check(status, "Reply sent");
    
    //close
    close(sock);
}
    