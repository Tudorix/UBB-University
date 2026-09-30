#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int n;
int potato;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


void* func(void* arg){
	int id = *((int*)arg);
	free(arg);

	while(1){
		pthread_mutex_lock(&mtx);

		if(potato < 0){
			pthread_mutex_unlock(&mtx);
			break;
		}

		int dec = 11 + rand() % 90;
		potato -= dec;
		printf("%d -> %d\n", id, dec);
		if(potato < 0){
			printf("Hot Potato -> %d\n", id);
			pthread_mutex_unlock(&mtx);
			break;
		}	
	
		pthread_mutex_unlock(&mtx);
		usleep(500000);
	}
	return NULL;
}

int main(int x, char** y){
	
	if(x < 2){
		printf("Error!\n");
		exit(1);
	}	

	srand(time(NULL));
	n = atoi(y[1]);
	printf("n = %d\n",n);
	potato = 1001 + (rand() % 9000);
	printf("Potato is: %d\n", potato);
	
	pthread_t t[n];
	for(int i = 0 ; i < n; i++){
		int *id = malloc(sizeof(int));
		*id = i;
		pthread_create(&t[i],NULL,func,id);
	}

	for(int i = 0;i < n;i++){
		pthread_join(t[i],NULL);
	}

	(void)x;
	(void)y;
	return 0;
}
