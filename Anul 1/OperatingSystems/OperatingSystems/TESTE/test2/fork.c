#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	int pid = getpid(); // Parent PID

	if(fork() == 0){
		int chPid = getpid(); // Child PID
		printf("Child Here!\n");
		exit(0);
	}
	
	printf("Parent Here!");
	wait(NULL);
	

	return 0;
}
