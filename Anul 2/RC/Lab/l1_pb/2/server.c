#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int server(){
    int serverSocket;

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

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

    return serverSocket;
}

int main(){
    int socket = server();

    if(listen(socket, 5) == -1){
        perror("listen");
        return 1;
    }

    while(1){
        int clientSocket;
        clientSocket = accept(socket, NULL, NULL);

        if (clientSocket == -1) {
            perror("accept");
            return 1;
        }

        char s[256];
        recv(clientSocket, s,sizeof(s),0);

        int cnt = 0;
        for(int i = 0; i < strlen(s); i++){
            if(s[i] == ' '){
                cnt++;
            }
        }

        send(clientSocket,&cnt,sizeof(cnt),0);
        printf("%s\n", s);
    }
    return 0;
}