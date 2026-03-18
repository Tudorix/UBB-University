#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	sleep(5);
	for(int i = 0; i < 3; i++){
		if(fork() == 0){
			sleep(10);
			exit(0);
		}
	}
	sleep(15);

	for(int i = 0; i < 3; i++){
		wait(NULL);
	}

	sleep(5);

	return 0;
}
