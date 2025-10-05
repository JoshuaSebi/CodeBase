//TCP

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define LOCALHOST inet_addr("127.0.0.1")
#define PORT 4000
#define BUFFER_SIZE 256

int main(){

    int sock;
    int c;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];

    void errorcheck(int x, char msg[]){
        if (x<0){
            perror("Failed");
            exit(0);
        }
        else{
            printf("\n%s",msg);
        }
    }

    sock = socket(AF_INET, SOCK_DGRAM,0);
    errorcheck(sock, "created socket\n");

    //Bind to socket
    addr.sin_port=htons(PORT);
    addr.sin_family=AF_INET;
    addr.sin_addr.s_addr=LOCALHOST;
    socklen_t len = sizeof(addr);

    //Communicate
    int status = -1;
    char msg[] = "Hello from client";

    status = sendto(sock,msg, sizeof(msg),0,sock,(struct sockaddr *) &addr, len);
    errorcheck(status, "message sent to server\n");
    status = recvfrom(sock, buffer, sizeof(buffer),0,sock,(struct sockaddr *) &addr, &len);
    errorcheck(status, "message received from server\n");   
    printf("%s\n", buffer);

    close(sock);
    return 0;
}