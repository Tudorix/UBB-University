#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	// Comun
	for(int i = 0; i < 3; i++){
		if(fork() == 0){
			// Pt copil
			printf("\t%d\n", getpid());
			for(int j = 0; j < 3; j++){
				if(fork() == 0){
					// Pt nepot
					printf("\t\t%d\n", getpid());
					exit(0);
				}
			}

			for(int j = 0; j < 3; j++)
				wait(NULL);
			exit(0);
		}
	}

	// Pt Parinte
	printf("%d %d\n", getpid(), getppid());

	for(int i = 0; i < 3; i ++){
		// Asteapta executia copilului; Altfel ZOMBIE
		wait(NULL);
	}

	return 0;
}
