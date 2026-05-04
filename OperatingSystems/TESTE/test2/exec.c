#include <stdio.h>
#include <unistd.h>

int main(){
	
	printf("Se printeaza\n");
	fflush(stdout);
	execlp("ls","ls","-l","-a",NULL);
	fflush(stdout);
	printf("Asta nu\n");
	return 0;
}
