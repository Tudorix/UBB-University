#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
	int a2b, b2a,n;

	a2b = open("a2b", O_WRONLY);
	b2a = open("b2a", O_RDONLY);

    n = 7;
	write(a2b, &n,sizeof(int));

	while(1){
		if(read(b2a,&n,sizeof(int)) <= 0) break;
			printf("A %d\n", n);
		if(n <= 0) break;

		n--;
		write(a2b, &n, sizeof(int));
	}

	close(a2b);
	close(b2a);

	(void) argc;
	(void) argv;
	return 0;
}
