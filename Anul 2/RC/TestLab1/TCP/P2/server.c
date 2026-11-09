#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void serve(int client_socket){
    int n;
    recv(client_socket,&n,sizeof(n),MSG_WAITALL);
    n = ntohl(n);

    char s[n];
    recv(client_socket,s,n,MSG_WAITALL);
    s[n] = '\0';

    int rez[2] = {0,0};
    for(int i = 0; i < n; i++){
        if(strchr("AEIOUaeiou",s[i])){
            rez[0]++;
            continue;
        }else if(!strchr(" ",s[i])){
            rez[1]++;
            continue;
        }
    }

    rez[0] = htonl(rez[0]);
    rez[1] = htonl(rez[1]);
    send(client_socket,rez,sizeof(rez),0);
}

int main(){
    struct sockaddr_in server;

    int server_sock = socket(AF_INET,SOCK_STREAM,0);

    if(server_sock == -1){
        perror("Socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(3663);
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_sock,(struct sockaddr*) &server,sizeof(server)) == -1){
        perror("Bind");
        return 1;
    }

    if(listen(server_sock,5) == -1){
        perror("Listen");
        return 1;
    }

    // Deservire Clienti
    while(1){
        int client_sock = accept(server_sock,NULL,NULL);

        if(client_sock == -1){
            perror("Client");
            return 1;
        }

        if(fork() == 0){
            close(server_sock);
            serve(client_sock);
            close(client_sock);
            exit(0);
        }else {
            close(client_sock);
        }
    }

    return 0;
}