#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
int main(){
	//int c2p[2];

	if(fork() == 0){
		int fd_1 = open("transf.txt",O_WRONLY | O_CREAT | O_TRUNC, 0644); 
		dup2(fd_1,1);
		execlp("ls","ls","-l","-a",NULL);
		
		exit(0);
	}

	wait(NULL);

	if(fork() == 0){
		int fd_2 = open("transf.txt", O_RDONLY, 0644);
		dup2(fd_2,0);
		execlp("wc", "wc","-l",NULL);
		exit(0);
	}
	wait(NULL);
	return 0;
}
