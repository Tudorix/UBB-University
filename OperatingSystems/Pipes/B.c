#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

// B

int main(){
	
	int a2b, b2a;
	a2b = open("A2B", O_RDONLY);		
	b2a = open("B2A", O_WRONLY);

		while(1){
			int a, b;
			read(a2b,&a,sizeof(int));
			read(a2b,&b,sizeof(int));

			int s = a + b;
			int p = a * b;

			write(b2a, &s,sizeof(int));
			write(b2a, &p,sizeof(int));

			if(s == p) break;
		}

		close(a2b);
		close(b2a);
		
	return 0;
}
	
