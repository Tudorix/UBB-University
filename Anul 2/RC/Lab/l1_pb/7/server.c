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
    int l,i;
    char s[256];

    recv(socket, &l, sizeof(l),0);
    recv(socket, &i, sizeof(i),0);
    recv(socket, s, sizeof(s),0);

    char r[256];
    strncpy(r,s + i, l);

    send(socket,r,sizeof(r),0);

    return 0;
}