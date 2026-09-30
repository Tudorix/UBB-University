#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int f[10];
pthread_mutex_t mtx[10];

void *func(void *arg){
	int *nr = (int*)arg;
	int x = *nr;
	int uc;

	// !!!!!!!!!!!!!!!!!
	free(arg);

	if(x == 0){
		pthread_mutex_lock(&mtx[0]);
		f[0]++;
		pthread_mutex_unlock(&mtx[0]);
	}

	if(x < 0){
		x *= -1;
	}

	// !!!!!!!!!!!!!!!!

	while(x){
		uc = x % 10;
		x /= 10;

		pthread_mutex_lock(&mtx[uc]);
		f[uc]++;
		pthread_mutex_unlock(&mtx[uc]);
	}

	(void) arg;
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc < 2){
		printf("Not enought arguments!\n");
		exit(1);
	}

	pthread_t t[argc - 1];
	
	for(int i = 0; i < 10; i++){
		pthread_mutex_init(&mtx[i],NULL);
	}

	for(int i = 0; i < argc - 1; i++){
		int *id = malloc(sizeof(int));
		*id = atoi(argv[i + 1]);
		pthread_create(&t[i],NULL, func, id);
	}

	for(int i =0 ; i< argc -1; i++){
		pthread_join(t[i], NULL);
	}

	for(int i = 0; i < 10; i++){
		pthread_mutex_destroy(&mtx[i]);
	}
		
	for(int i = 0; i < 10; i++){
		printf("%d -> %d\n", i , f[i]);
	}

	return 0;
}
