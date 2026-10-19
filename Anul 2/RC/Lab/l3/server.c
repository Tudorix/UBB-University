#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h> // pentru IPv4
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
    struct sockaddr_in server, client;

    int ServerSocket;

    ServerSocket = socket(AF_INET,SOCK_STREAM,0);

    if(ServerSocket == -1){
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(6767);
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(ServerSocket,(struct sockaddr*)&server, sizeof(server)) == -1){
        perror("bind");
        return 1;
    }

    if(listen(ServerSocket,5) == -1){
        perror("listen");
        return 1;
    }

    printf("Binded\n");

    while(1){
        int clientSocket = accept(ServerSocket,NULL,NULL);
        
        if(clientSocket == -1){
            perror("accept");
            return 1;
        }
        printf("Accepted\n");

        char s[256];
        recv(clientSocket,s,sizeof(s),0);

        printf("%s\n",s);

        strcpy(s,"Test");
        send(clientSocket,s,strlen(s),0);
        close(clientSocket);
    }
}
