#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int server(){
    int serverSocket;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if(serverSocket == -1){
        perror("socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
    
    server.sin_addr.s_addr = INADDR_ANY;

    int result = bind(serverSocket, (struct sockaddr *)&server, sizeof(server));

    if(result == -1){
        perror("bind");
        return 1;
    }

    if(listen(serverSocket, 5) == -1){
        perror("listen");
        return 1;
    }

    int clientSocket;

    clientSocket = accept(serverSocket, NULL, NULL);

    if (clientSocket == -1) {
        perror("accept");
        return 1;
    }

    return clientSocket;
}

int main(){
    int socket = server();
    char s1[256], s2[256];
    recv(socket, s1,sizeof(s1),0);
    recv(socket, s2,sizeof(s2),0);

    char inter[513] = "";

    int i = 0;
    int j = 0;
    int k = 0;
    int n = strlen(s1);
    int m = strlen(s2);

    while(i < n && j < m){
        if(s1[i] < s2[j]){
            inter[k++] = s1[i++];
        }else{
            inter[k++] = s2[j++];
        }
    }

    while(i < n){
        inter[k++] = s1[i++];
    }

    while(j < m){
        inter[k++] = s2[j++];
    }

    inter[n + m] = '\0';

    send(socket,inter,sizeof(inter),0);
    return 0;
}