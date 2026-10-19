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
    char r[11];

    recv(socket, s1, sizeof(s1),0);
    recv(socket, s2, sizeof(s2),0);

    int f[10] = {0,0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < strlen(s1); i++){
        if(s1[i] >= '0' && s1[i] <= '9'){
            f[s1[i] - '0'] = 1;
        }
    }

    for(int i = 0; i < strlen(s2); i++){
        if(s2[i] >= '0' && s2[i] <= '9'){
            f[s2[i] - '0']++;
        }
    }

    int k = 0;
    for(int i = 0; i < 10; i++){
        if(f[i] > 1){
            char c = '0' + i;
            printf("%c\n", c);
            r[k++] = c;
        }
    }
    r[k] = '\0';

    printf("%s;\n", r);

    send(socket,r,sizeof(r),0);

    return 0;
}