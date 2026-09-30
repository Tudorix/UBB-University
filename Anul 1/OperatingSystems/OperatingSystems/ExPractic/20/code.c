#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int N, M;
pthread_mutex_t *mtx;
pthread_barrier_t b;

void* func(void* arg){
	int id = *((int*)arg);
	int c = M - 1;
	pthread_barrier_wait(&b);
	while(c != -1){
		pthread_mutex_lock(&mtx[c]);
		printf("[Threadul] %d - a ajuns la [mutexul] %d\n",id,c);
		int n = 100000 + rand() % 600000;
		usleep(n);
		pthread_mutex_unlock(&mtx[c]);
		c--;
	}
	return 0;
}

int main(int argc, char** argv){
	
	if(argc != 3) return 1;

	N = atoi(argv[1]);
	M = atoi(argv[2]);

	pthread_barrier_init(&b,NULL,N);

	mtx = malloc(sizeof(pthread_mutex_t) * M);
	for(int i = 0; i < M; i++) pthread_mutex_init(&mtx[i],NULL);

	pthread_t t[N];
	int id[N];
	for(int i = 0; i < N; i++){
		id[i] = i;
		pthread_create(&t[i],NULL,func,&id[i]);
	}
	
	for(int i = 0 ; i < N; i++){ pthread_join(t[i],NULL);}
	for(int i = 0; i < M ; i++){ pthread_mutex_destroy(&mtx[i]);}
	pthread_barrier_destroy(&b);
	free(mtx);
	return 0;
}

