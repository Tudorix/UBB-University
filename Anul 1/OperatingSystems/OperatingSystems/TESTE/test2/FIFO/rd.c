#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	
	int fd = open("fifo1",O_RDONLY);

	if(fd == -1){
		printf("Error");
		exit(1);
	}

	char buf[105];
	read(fd,buf,105);

	printf("%s", buf);

	close(fd);
	return 0;
}
