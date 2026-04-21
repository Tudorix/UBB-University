#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	int p2c[2];
	int c2p[2];

	//  0 - READ
	//  1 - WRITE
	
	// Make pipe
	pipe(p2c);
	pipe(c2p);

	if(fork() == 0){
		// Pipe is inherited
		close(c2p[0]);
		// INchizi capatul nefolosit
		close(p2c[1]);
		int nr;

		// Citesti din pipe
		read(p2c[0],&nr, sizeof(int));

		nr *= 2;

		write(c2p[1],&nr,sizeof(int));

		close(p2c[0]);
		close(c2p[1]);
		exit(0);
	}
	
	close(c2p[1]);
	close(p2c[0]);

	int n;
	scanf("%d",&n);

	// Scrie in Pipe
	write(p2c[1],&n,sizeof(int));
	
	read(c2p[0], &n, sizeof(int));

	printf("%d\n", n);
	
	close(c2p[0]);
	close(p2c[1]);
	// Este practic un await
	wait(NULL);
	
	return 0;
}
	
