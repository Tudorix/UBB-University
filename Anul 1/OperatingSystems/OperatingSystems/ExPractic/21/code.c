#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <math.h>

sem_t *s;
int N;

void* func(void* arg){	
	for(int i = 0; i < N; i++){
		sem_wait(&s[i]);
		usleep(200000);
		printf("Am ajuns la checkpointul %d\n", i);
		sem_post(&s[i]);
	}
	(void) arg;
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc != 2){
		exit(1);
	}

	N = atoi(argv[1]);
	
	int n2 = 1;
	for(int i = 0; i < N; i++){
		n2 *= 2;
	}

	printf("2^n = %d\n", n2);

	s = malloc(sizeof(sem_t) * N);
	for(int i = 0; i < N; i++){
		sem_init(&s[i],0,pow(2,N - i - 1));
	}
	
	pthread_t t[n2];
	for(int i = 0; i < n2; i++){
		pthread_create(&t[i],NULL,func,NULL);
	}

	for(int i = 0; i < n2; i++){
		pthread_join(t[i],NULL);
	}

	for(int i = 0; i < N; i++){
		sem_destroy(&s[i]);
	}

	free(s);
	return 0;
}
