#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 4000
#define BUFFER_SIZE 256
#define LOCALHOST inet_addr("127.0.0.1")

void main(){

    //define variables
    int sock, client_sock;
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
    sock = socket(AF_INET, SOCK_STREAM, 0);
    error_check(sock,"Socket Created");

    //bind address server
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);
    server_addr.sin_addr.s_addr=LOCALHOST;
    int b = bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    error_check(b, "Binding Done");

    //listen
    int l = listen(sock, 5);
    error_check(l, "Listening");

    //accept
    socklen_t len = sizeof(client_addr);
    client_addr.sin_family=AF_INET;
    int a = accept(sock, (struct sockaddr *) &client_addr, &len);
    error_check(a, "Accepted");

    //Operations
    char reply [] = "Hello from server";
    int status = -1;
    status = recv(a, buffer, BUFFER_SIZE, 0);
    error_check(status, "Reply Received");
    printf("Client: %s\n", buffer);
    status = send(a, reply, sizeof(reply), 0);
    error_check(status, "Reply Sent");  
    close(sock);
    close(a);
}