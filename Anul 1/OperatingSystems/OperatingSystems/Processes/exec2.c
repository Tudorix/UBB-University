#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/time.h>

int main(int argc, char **argv){
	
	struct timeval t0, t1;
	gettimeofday(&t0, NULL);

	if(fork() == 0){
		execlp(argv[1],argv[1],NULL);
		exit(1);
	}
	int status;
	wait(&status);

	gettimeofday(&t1, NULL);
	printf("Programul %s a rulat pentru %ld micro secund\n", argv[1], (t1.tv_usec - t0.tv_usec));
	return WEXITSTATUS(status);
}
