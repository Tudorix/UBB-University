#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void serve(int client_socket){
    int running = 1;
    while(running){
        
        int x;
        recv(client_socket,&x,sizeof(x),MSG_WAITALL);
        x = ntohl(x);
        int a,b;
        int status;
        switch (x)
        {
        case 1:
            status = htonl(200);
            send(client_socket,&status, sizeof(int),0);
            recv(client_socket,&a,sizeof(a),MSG_WAITALL);
            recv(client_socket,&b,sizeof(b),MSG_WAITALL);
            b = ntohl(b); a = ntohl(a);

            int suma = a + b;
            suma = htonl(suma);
            send(client_socket,&suma,sizeof(int),0);
            break;
        case 2:
            status = htonl(200);
            send(client_socket,&status, sizeof(int),0);
            recv(client_socket,&a,sizeof(a),MSG_WAITALL);
            recv(client_socket,&b,sizeof(b),MSG_WAITALL);
            b = ntohl(b); a = ntohl(a);

            int sub = a - b;
            sub = htonl(sub);
            send(client_socket,&sub,sizeof(int),0);
            break;
        case 3:
            status = htonl(200);
            send(client_socket,&status, sizeof(int),0);
            recv(client_socket,&a,sizeof(a),MSG_WAITALL);
            recv(client_socket,&b,sizeof(b),MSG_WAITALL);
            b = ntohl(b); a = ntohl(a);

            int mul = a * b;
            mul = htonl(mul);
            send(client_socket,&mul,sizeof(mul),0);
            break;
        case 4:
            running = 0;
            break;
        default:
            status = htonl(404);
            send(client_socket,&status, sizeof(int),0);
            break;
        }
    }

}

int main(){
    struct sockaddr_in server;

    int server_sock = socket(AF_INET,SOCK_STREAM,0);

    if(server_sock == -1){
        perror("Socket");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(3663);
    server.sin_addr.s_addr = INADDR_ANY;

    if(bind(server_sock,(struct sockaddr*) &server,sizeof(server)) == -1){
        perror("Bind");
        return 1;
    }

    if(listen(server_sock,5) == -1){
        perror("Listen");
        return 1;
    }

    // Deservire Clienti
    while(1){
        int client_sock = accept(server_sock,NULL,NULL);

        if(client_sock == -1){
            perror("Client");
            return 1;
        }

        if(fork() == 0){
            close(server_sock);
            serve(client_sock);
            close(client_sock);
            exit(0);
        }else {
           close(client_sock);
        }
    }

    return 0;
}