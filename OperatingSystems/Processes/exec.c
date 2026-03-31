#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv){
	
	for(int i = 1; i <= argc; i++){
		if(fork() == 0){
			if(execlp(argv[i],argv[i],NULL) == -1){
				fprintf(stderr,"A crapat! : %s \n", strerror(errno));
			}
			exit(0);
		}
		int status;
		wait(&status);
		if(WIFEXITED(status) && WEXITSTATUS(status) != 0){
			fprintf(stderr, "A crapat iar %d\n", WEXITSTATUS(status));
		}
	}
	
	return 0;
}
