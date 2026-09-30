#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	printf("Parinte %d %d a\n", getpid(), getppid());
	for(int i = 0; i < 3; i++){
		if(fork() == 0){
			printf("Fiu %d %d %d\n", getpid(), getppid(), i);
			exit(0);
		}
	}

	for(int i = 0; i < 3; i++){
		wait(NULL);
	}

	printf("%d %d b\n", getpid(), getppid());
	return 0;
}
