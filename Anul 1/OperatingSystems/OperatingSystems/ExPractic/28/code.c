#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int N;
int *v;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

int sorted = 0;

int e_sortat(){
	for(int i = 0; i < N - 1; i++){
		if(v[i] > v[i + 1]) return 0;
	}
	return 1;
}

void* srt(void* arg){
	while(1){
		pthread_mutex_lock(&mtx);

		if(sorted == 1){
			pthread_mutex_unlock(&mtx);
			break;
		}

		int i,j, aux;
		i = rand() % N;
		j = rand() % N;

		if(i < j && v[i] > v[j]){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}else if(i > j && v[i] < v[j]){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
		}

		sorted = e_sortat();

		if(sorted == 1){
			pthread_cond_signal(&c);
		}	

		pthread_mutex_unlock(&mtx);
	}
	(void) arg;
	return NULL;
}

void* prt(void* arg){
	pthread_mutex_lock(&mtx);
	while(sorted == 0){
		pthread_cond_wait(&c,&mtx);
	}

	for(int i = 0; i < N; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	pthread_mutex_unlock(&mtx);
	(void) arg;
	return NULL;
}


int main(int argc, char** argv){
	if(argc != 2){
		printf("Noob\n");
		exit(1);
	}

	N = atoi(argv[1]);

	v = malloc(sizeof(int) * N);
	for(int i = 0; i < N; i++){
		v[i] = rand() % 1000;
	}
	// Check
	for(int i = 0; i < N; i++){
		printf("%d ", v[i]);
	}
	printf("\n");

	pthread_t t[N];
	pthread_t p;
	for(int i = 0; i < N; i++){
		pthread_create(&t[i],NULL,srt,NULL);
	}
	pthread_create(&p,NULL,prt,NULL);

	for(int i = 0; i < N; i++){
		pthread_join(t[i],NULL);
	}
	pthread_join(p,NULL);

	free(v);
	return 0;
}
