#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

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
    char s1[256], s2[256], s3[512];

    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);

    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    int socket = client();

    send(socket,s1,sizeof(s1),0);
    send(socket,s2,sizeof(s2),0);

    recv(socket,s3,sizeof(s3),0);

    printf("%s\n",s3);
    return 0;
}