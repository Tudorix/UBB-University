#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
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

    int n;
    recv(clientSocket, &n, sizeof(n), 0);

    int x;
    int sum = 0;
    for(int i = 0; i < n; i++){
        recv(clientSocket, &x, sizeof(x), 0);
        sum += x;
    }
    
    send(clientSocket,&sum,sizeof(sum),0);
    
    return 0;
}