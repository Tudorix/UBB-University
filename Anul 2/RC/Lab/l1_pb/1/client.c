#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h> // pentru IPv4
#include <arpa/inet.h>

struct sockaddr_in server; // adresa serverului IPv4

int main(){
    int n;
    int sock;

    printf("Numar: ");
    scanf("%d", &n);

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1){
        perror("socket");
        return 1;
    }

    server.sin_family = AF_INET; // Serverul foloseste IPv4
    server.sin_port = htons(1234); // Setam Portul

    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    
    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));

    if(result == -1){
        perror("connect");
        return 1;
    }

    send(sock,&n,sizeof(n),0);

    int x;
    for(int i = 0; i < n; i++){
        scanf("%d",&x);
        send(sock,&x,sizeof(x),0);
    }

    recv(sock,&x,sizeof(x),0);
    printf("Suma este: %d\n", x);
    
    return 0;
}