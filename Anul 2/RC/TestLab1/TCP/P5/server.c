#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

void serve(int clinet){
    int n;
    recv(clinet,&n,sizeof(n),MSG_WAITALL);
    n = ntohl(n);

    char maxN[100];
    float maxMed = 0;
    for(int i = 0; i < n; i++){
        char Nume[101];
        int l;
        recv(clinet,&l,sizeof(l),MSG_WAITALL);
        l = ntohl(l);
        recv(clinet,Nume,l,MSG_WAITALL);
        Nume[l] = '\0';

        int k;
        recv(clinet,&k,sizeof(int),MSG_WAITALL);
        k = ntohl(k);

        float medie = 0;
        for(int j = 0; j < k; j++){
            int x;
            recv(clinet,&x,sizeof(int),MSG_WAITALL);
            x = ntohl(x);
            medie += x;
        }

        medie = medie / k;
        if(medie > maxMed){
            maxMed = medie;
            strcpy(maxN,Nume);
        }
    }

    int intMed = maxMed * 100;
    intMed = htonl(intMed);
    send(clinet,&intMed,sizeof(int),0);

    int leng = strlen(maxN);
    leng = htonl(leng);
    send(clinet,&leng,sizeof(int),0);
    send(clinet,maxN,strlen(maxN),0);

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