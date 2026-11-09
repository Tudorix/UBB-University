#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

int prim(int a){
    if(a <= 1) return 0;
    if(a % 2 == 0 && a != 2) return 0;
    for(int i = 3; i <= a/2; i += 2){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

void serve(int clinet){
    int n;
    recv(clinet,&n,sizeof(n),MSG_WAITALL);
    n = ntohl(n);

    int rez[n];
    int k = 0;
    int x;
    for(int i  = 0; i < n; i++){
        recv(clinet,&x,sizeof(x),MSG_WAITALL);
        x = ntohl(x);
        if(prim(x)){
            rez[k++] = x;
        }
    }

    k = htonl(k);
    send(clinet,&k,sizeof(k),0);
    for(int i = 0; i < k; i++){
        rez[i] = htonl(rez[i]);
        send(clinet,&rez[i],sizeof(rez[i]),0);
    }
    close(clinet);
}

int main(){
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(3663);
    server.sin_addr.s_addr = INADDR_ANY;

    int serverSock = socket(AF_INET,SOCK_STREAM,0);

    if(serverSock == -1){
        perror("Error");
        return 1;
    }

    if(bind(serverSock,(struct sockaddr *) &server,sizeof(server)) == -1){
        perror("Error");
        return 1;
    }

    if(listen(serverSock,5) == -1){
        perror("Error");
        return 1;
    }

    while(1){
        int sockClinet = accept(serverSock,NULL,NULL);

        if(sockClinet == -1){
            perror("Error");
            return 1;
        }

        if(fork() == 0){
            close(serverSock);
            serve(sockClinet);
            exit(0);
        }else{
            close(sockClinet);
        }
    }
    return 0;
}