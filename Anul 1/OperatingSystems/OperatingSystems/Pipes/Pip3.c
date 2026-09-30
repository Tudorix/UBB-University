#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	
	int p2c[2];
	int c2p[2];

	pipe(p2c);
	pipe(c2p);

	if(fork() == 0){
		close(p2c[1]);
		close(c2p[0]);
		
		while(1){
			int a, b;
			read(p2c[0],&a,sizeof(int));
			read(p2c[0],&b,sizeof(int));

			int s = a + b;
			int p = a * b;

			write(c2p[1], &s,sizeof(int));
			write(c2p[1], &p,sizeof(int));

			if(s == p) break;
		}

		close(p2c[0]);
		close(c2p[1]);
		
		exit(0);
	}

	close(p2c[0]);
	close(c2p[1]);
	
	int x,y;
	while(1){
		scanf("%d %d",&x, &y);
		write(p2c[1],&x,sizeof(int));
		write(p2c[1],&y,sizeof(int));

		int S , P;

		read(c2p[0],&S,sizeof(int));
		read(c2p[0],&P,sizeof(int));

		printf("x + y = %d\nx * y = %d\n",S,P);
		if(S == P) break;
	}

	close(p2c[1]);
	close(c2p[0]);

	wait(NULL);
	return 0;
}
	
