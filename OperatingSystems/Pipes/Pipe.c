#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	int p2c[2];

	//  0 - READ
	//  1 - WRITE
	
	// Make pipe
	pipe(p2c);

	if(fork() == 0){
		// Pipe is inherited

		// INchizi capatul nefolosit
		close(p2c[1]);
		int nr;

		// Citesti din pipe
		read(p2c[0],&nr, sizeof(int));

		printf("%d",nr);
		close(p2c[0]);
		exit(0);
	}

	close(p2c[0]);

	int n;
	scanf("%d",&n);

	// Scrie in Pipe
	write(p2c[1],&n,sizeof(int));
	
	close(p2c[1]);
	// Este practic un await
	wait(NULL);
	
	return 0;
}
	
