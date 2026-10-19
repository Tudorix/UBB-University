#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h> // pentru IPv4
#include <arpa/inet.h>

int main(){

    int sock = socket(AF_INET,SOCK_STREAM,0);

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(1234);

    if(bind(sock,(struct sockaddr_in*)&server,sizeof(server)) == -1){
        perror("socket");
        return 1;
    }



    

    return 0;
}