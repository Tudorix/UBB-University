#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char **argv){
	int a[4] = {1,2,3,4};
	int p[2]; // FILE DESCRIPTORS

	pipe(p);
	if(fork() == 0){
		close(p[0]);//Inchide capatul de citire in fiu
		a[2] += a[3];
		write(p[1],&a[2],sizeof(int));//Scrie in pipe
		close(p[1]);//Ichide capatu de scriere in fiu
		exit(0);
	}
	close(p[1]);//Inchide scriere de citire in parinte
	a[0] += a[1];

	read(p[0],&a[2],sizeof(int));//Citeste din pipe
	close(p[0]);//Ichide capatu de scriere in parinte
	wait(0);

	a[0] += a[2];

	printf("%d\n", a[0]);
	(void)argc;
	(void)argv;
	return 0;
}
