#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	
	// File for redir output
	int fd = open("testFile", O_CREAT | O_TRUNC | O_WRONLY, 0644);

	if(fd == -1){
		printf("File Error");
		exit(1);
	}

	printf("std output");

	fflush(stdout);

	int saved_stdout = dup(1); // Save original stdout

	dup2(fd,1);

	printf("New Output");

	close(fd);
	return 0;
}
