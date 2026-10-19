#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void increment_frequency(int *frequency, char c) {
    if(c >= 'a' && c <= 'z') {
        frequency[c - 'a']++;
    }
}



int main(int argc, char **argv) {
    int frequency[30];
    char* buffer;
    int i;
    int capacity = 26;
	
    buffer = (char*)malloc(1024*sizeof(char));
	
    for(i=0; i < capacity; i++) {
        frequency[i] = 0;
    }
	
	int fd;
	if(argc >= 2){
    	fd = open(argv[1], O_RDONLY);
    	if(fd < 0) {
        	perror("Error opening the file");
       		return 1;
    	}
	}

    while(1) {
        int k = read(fd, buffer, 1024);
        if(k <= 0) {
            break;
        }
        for(i=0; i<k; i++) {
            increment_frequency(frequency, buffer[i]);
        }
    }

    close(fd);

    for(i=0; i < capacity; i++) {
        if(frequency[i] == 0) {
            continue;
        }
        printf("Count = %d character = %c\n", frequency[i], i + 'a');
    }

    free(buffer);
    return 0;
}
