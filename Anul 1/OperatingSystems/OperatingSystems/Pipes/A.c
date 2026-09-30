#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	
	int a2b, b2a;

	a2b = open("A2B", O_WRONLY);
	b2a = open("B2A", O_RDONLY);

	int x,y;
	while(1){
		scanf("%d %d",&x, &y);
		write(a2b,&x,sizeof(int));
		write(a2b,&y,sizeof(int));

		int S , P;

		read(b2a,&S,sizeof(int));
		read(b2a,&P,sizeof(int));

		printf("x + y = %d\nx * y = %d\n",S,P);
		if(S == P) break;
	}

	close(a2b);
	close(b2a);

	return 0;
}
	
