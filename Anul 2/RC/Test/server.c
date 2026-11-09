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
    // Comunicare cu UDP
    int l;
    char s[255];
    recv(clinet,&l,sizeof(int),MSG_WAITALL);
    l = ntohl(l);
    recv(clinet,s,l,MSG_WAITALL);
    s[l] = '\0';

    int port;
    recv(clinet,&port,sizeof(int),0);
    port = ntohl(port);
    close(clinet);

    printf("%s , %d", s, port);

    int udpSock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in client;
    memset(&client, 0, sizeof(client));

    client.sin_family = AF_INET;
    client.sin_port = htons(port);
    inet_pton(AF_INET, s, &client.sin_addr);

    // Cuvant initial
    char c[1005];

    printf("\nCuvant initial: ");
    scanf("%1004s", c);

    int length = strlen(c);
    int len = htonl(length);

    sendto(udpSock, &len, sizeof(int), 0,(struct sockaddr*)&client, sizeof(client));
    sendto(udpSock, c, length, 0,(struct sockaddr*)&client, sizeof(client));

    l = strlen(c);

    char ultimele[3];
    ultimele[0] = c[l - 2];
    ultimele[1] = c[l - 1];
    ultimele[2] = '\0';

    while (1) {
        // Primim lungimea cuvantului
        recvfrom(udpSock, &length, sizeof(int), 0, NULL, NULL);
        length = ntohl(length);

        if (length < 2 || length >= sizeof(c)){
            strcpy(c,"STOP");

            length = strlen(c);
            len = htonl(length);

            sendto(udpSock, &len, sizeof(int), 0,(struct sockaddr*)&client, sizeof(client));
            sendto(udpSock, c, length, 0,(struct sockaddr*)&client, sizeof(client));
            break;
        }

        // Primim cuvantul
        recvfrom(udpSock, c, length, 0, NULL, NULL);
        c[length] = '\0';

        printf("Primit: %s\n", c);

        if (strncmp(ultimele, c, 2) == 0) {
            // Trimitem urmatorul cuvant
            printf("Cuvant: ");
            scanf("%1004s", c);

            length = strlen(c);
            len = htonl(length);

            sendto(udpSock, &len, sizeof(int), 0,(struct sockaddr*)&client, sizeof(client));
            sendto(udpSock, c, length, 0,(struct sockaddr*)&client, sizeof(client));

            length = strlen(c);
            strcpy(ultimele, c + length - 2);
        } else {
            strcpy(c,"STOP");

            length = strlen(c);
            len = htonl(length);

            sendto(udpSock, &len, sizeof(int), 0,(struct sockaddr*)&client, sizeof(client));
            sendto(udpSock, c, length, 0,(struct sockaddr*)&client, sizeof(client));
            break;
        }
    }

    close(udpSock);
    printf("Gata jocul\n");

}

int main(){
    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
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