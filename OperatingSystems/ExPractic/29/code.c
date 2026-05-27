#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int *v;

pthread_barrier_t b;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* func(void* arg){
	int id = *((int*)arg);
	free(arg);
	
	printf("Threadul cu id %d\n", id);
	
	int ver;
	int nr = 10 + rand() % 20;
	v[id] = nr;
	pthread_barrier_wait(&b);

	while(1){
		pthread_mutex_lock(&mtx);
		if(v[id] < 0){
			pthread_mutex_unlock(&mtx);
			break;
		}

		ver = 0;

		for(int i = 0; i < n; i++){
			if(i != id){
				if(v[i] > 0) ver = 1;
				v[i]--;
			}
		}

		if(ver == 0){
			pthread_mutex_unlock(&mtx);
			break;
		}

		pthread_mutex_unlock(&mtx);
	}

	return NULL;
}	

int main(){
	scanf("%d",&n);

	srand(time(NULL));
	pthread_barrier_init(&b, NULL, n);

	pthread_t t[n];
	v = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		int* id = malloc(sizeof(int));
		*id = i;
		pthread_create(&t[i],NULL,func,id);
	}

	for(int i = 0; i < n; i++){
		pthread_join(t[i],NULL);
	}
	
	for(int i = 0; i < n; i++){
		printf("%d\n", v[i]);
	}

	pthread_barrier_destroy(&b);
	free(v);

	return 0;
}
