#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int copii[3];

void handler(int signal){
	if(signal == SIGUSR2){
		for(int i = 0 ; i < 3; i++){
			kill(copii[i],SIGKILL);
		}
	}else if(signal == SIGUSR1){
		printf("Nyancat");
	}
}

int main(){
	for(int i = 0 ; i < 3; i++){
		if(fork() == 0){
			copii[i] = getpid();
			printf("%d\n", getpid());
			while(1);
		}
		
	}

	
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);


	wait(NULL);
	wait(NULL);
	wait(NULL);
	return 0;
}
