#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int N, M = 1;
int *v;

pthread_barrier_t bar;

void* func(void* arg){
	int id = *((int*)arg);
	free(arg);

	// 1. [M/2 , M-1]
	// 2. [M/4 , M/2 - 1]
	// 3. [M/8 , M/4 - 1]
	// ...
	// k. [1,1]; k = log2(M)
	
	int a = M/2;
	int b = M - 1;
	int p = 2;
	int iter = 0;
	while(a > 0){
		if(id >= a && id <= b){
			int idx = (id - a) * p;
			v[idx] += v[idx + p/2];
			printf("Threadul %d a calculat %d\n", id, v[idx]);
		}
		
		iter++;
		p *= 2;
		a /= 2;
		b = 2 * a - 1;
		if(pthread_barrier_wait(&bar) != 0){
			printf("\nBariera %d\n",iter);
		}
		pthread_barrier_wait(&bar);
	}
	
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc < 2){
		printf("Not enough args!\n");
		exit(1);
	}

	N = atoi(argv[1]);

	while(M < N) M <<= 1;

	v = (int*)malloc(sizeof(int) * M);
	for(int i = 0; i < N; i++){
		scanf("%d", &v[i]);
	}

	for(int i = N; i< M; i++) v[i] = 0;
	
	//Barrier Init
	pthread_barrier_init(&bar,NULL,M - 1);

	pthread_t t[M - 1];
	for(int i = 0 ; i < M - 1; i++){
		int *id = malloc(sizeof(int));
		*id = i + 1;
		pthread_create(&t[i], NULL, func,id);
	}

	for(int i = 0 ; i < M - 1; i++){
		pthread_join(t[i], NULL);
	}

	printf("%d\n",v[0]);

	pthread_barrier_destroy(&bar);
	free(v);
	return 0;
}
