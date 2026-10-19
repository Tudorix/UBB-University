/* Enunt: Un server primeste numere de la clienti si le afiseaza pe ecran. Serverul trimite inapoi fiecarui client numarul.

Compilare: 
	gcc server.c -o server
	gcc client.c -o client
	
Rulare in doua terminale diferite:
	./server
	./client
*/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
  int clientSocket, nr;
  char buffer[1024];
  char mesaj[256];
  struct sockaddr_in serverAddr;

  clientSocket = socket(AF_INET, SOCK_STREAM, 0);				/* Create the socket. The three arguments are:  1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  
  serverAddr.sin_family = AF_INET;						/* Address family = Internet */
  serverAddr.sin_port = htons(8889);							/* Set port number*/
  serverAddr.sin_addr.s_addr = inet_addr("192.168.40.153");				/* Set IP address to localhost */
   
  connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof serverAddr);
  printf("Introduceti textul:\n");
  scanf("%s",mesaj);
  printf("Trimit la server %s\n",mesaj); 

  send(clientSocket,mesaj,sizeof(mesaj),0);

  recv(clientSocket, buffer, sizeof(buffer), 0);						/* Read the message from the server into the buffer */

  printf("Data received: %s\n",buffer);   					/* Print the received message */

  close(clientSocket);

  return 0;
}