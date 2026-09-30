#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
	int fd = open("fifo1", O_WRONLY);

	if(fd == -1){
		printf("Error");
		exit(1);
	}

	char buf[105] = "Message from FIFO!";
	write(fd,&buf,105);

	close(fd);

	return 0;
}
