#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* func(void* arg){
	char *s = (char*)arg;
	
	for(unsigned long int i = 0; i < strlen(s); i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] -= 'a' - 'A';
		}
	}

	return NULL;
}

int main(int argc, char** argv){
	
	if(argc < 2){
		exit(1);
	}

	pthread_t t[argc - 1];

	for(int i = 0; i < argc - 1; i++){
		pthread_create(&t[i],NULL,func,argv[i + 1]);
	}

	for(int i = 0; i < argc - 1; i++){
		pthread_join(t[i],NULL);
	}

	for(int i = 1; i < argc; i++){
		printf("%s\n",argv[i]);
	}
	
	return 0;
}
