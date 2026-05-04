#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int c2p[2];
	int a = 2;
	int b = 3;

	pipe(c2p);

	if(fork() == 0){
		close(c2p[0]);
		int sum = a + b;
		write(c2p[1],&sum,sizeof(int));
		close(c2p[0]);

		exit(0);
	}

	close(c2p[1]);
	int rez;
	read(c2p[0],&rez,sizeof(int));

	printf("Sum = %d", rez);
	wait(NULL);

	return 0;
}
