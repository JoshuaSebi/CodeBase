#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 3025
#define BUFFER_SIZE 256
#define LOCALHOST inet_addr("127.0.0.1")

void main(){

    //define variables
    int sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    //error check
    void error_check(int s, char msg[]){
        if (s<0){
            perror("Failed");
            exit(0);
        }
        else{
            printf("\n%s\n",msg);
        }  
    }
    
    //create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    error_check(sock,"Socket Created");


    //Bind address server
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);
    server_addr.sin_addr.s_addr=LOCALHOST;

    socklen_t len = sizeof(server_addr);
    int b = bind(sock, (struct sockaddr *) &server_addr, len);
    error_check(b, "Binding Done");

    //accept
    socklen_t clen = sizeof(client_addr);
    char reply [] = "Hello from server";
    int status = -1;
    status = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_addr, &clen);
    error_check(status, "Reply Received");
    printf("Client: %s\n", buffer);
    status = sendto(sock, reply, sizeof(reply), 0, (struct sockaddr *) &client_addr, clen);
    error_check(status, "Message Sent");

    //close
    close(sock);
}

