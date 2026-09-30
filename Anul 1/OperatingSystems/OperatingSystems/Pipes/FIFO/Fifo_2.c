#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
	
	int fd_a2b, fd_b2a;
	fd_a2b = open("a2b",O_RDONLY);
	fd_b2a = open("b2a",O_WRONLY);

	int n;
	while(1){
		read(fd_a2b, &n, sizeof(int));
		
		if(n == 0){
			break;
		}

		printf("B %d\n",n);
		n--;
		write(fd_b2a,&n,sizeof(int));
	}

	close(fd_a2b);
	close(fd_b2a);

	return 0;
}	
