#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(3663);
    server.sin_addr.s_addr = INADDR_ANY;

    int sock = socket(AF_INET,SOCK_DGRAM,0);

    if(bind(sock,(struct sockaddr*)&server,sizeof(server)) == -1){
        perror("Error");
        return 1;
    }

    while(1){
        struct sockaddr_in client;
        int v[2];

        socklen_t len = sizeof(client);
        recvfrom(sock,v,sizeof(v),MSG_WAITALL,(struct sockaddr*)&client,&len);
        v[0] = ntohl(v[0]);
        v[1] = ntohl(v[1]);

        int suma = v[0] + v[1];
        suma = htonl(suma);
        sendto(sock,&suma,sizeof(suma),0,(struct sockaddr*)&client,len);
    }
}