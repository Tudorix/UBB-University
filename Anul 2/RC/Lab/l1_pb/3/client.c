#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int client(){
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        perror("socket");
        return 1;
    }

    struct sockaddr_in server;

    server.sin_family = AF_INET; // Serverul foloseste IPv4
    server.sin_port = htons(1234); // Setam Portul

    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    
    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));

    if(result == -1){
        perror("connect");
        return 1;
    }

    return sock;
}

int main(){
    char s[256];
    fgets(s, sizeof(s), stdin);

    int socket = client();

    send(socket,s,sizeof(s),0);

    recv(socket,s,sizeof(s),0);

    printf("%s\n",s);
    return 0;
}