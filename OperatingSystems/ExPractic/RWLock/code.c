#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int R, W;
pthread_rwlock_t lk;
int a[10];
int gata = 0;

void* citeste(void* arg){
	(void) arg;
	int nr = 15;
	while(nr > 0){
		nr--;
		pthread_rwlock_rdlock(&lk);
		for(int i = 0; i < 10; i++){
			printf("%d ", a[i]);
		}
		printf("\n");
		pthread_rwlock_unlock(&lk);
		usleep(50000);
	}
	int *test = malloc(sizeof(int));
	*test = rand() % 10;
	return test;
}

void* scrie(void* arg){
	(void) arg;
	for(int i = 0; i < 5; i++){
		pthread_rwlock_wrlock(&lk);
		a[rand() % 10] += rand() % 5;
		printf("Am scris\n");
		pthread_rwlock_unlock(&lk);
		usleep(300000);
	}
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc < 3){
		printf("Not enoigh args!\n");
		exit(1);
	}

	R = atoi(argv[1]);
	W = atoi(argv[2]);

	pthread_rwlock_init(&lk,NULL);

	pthread_t c[R];
	pthread_t s[W];
	
	for(int i = 0; i < R; i++){
		pthread_create(&c[i],NULL,citeste,NULL);
	}

	for(int i = 0; i < W; i++){
		pthread_create(&s[i],NULL,scrie,NULL);
	}

	for(int i = 0 ; i < R; i++){
		int *test;
		pthread_join(c[i],(void**)&test);
		printf("Test val : %d\n",*test);
		free(test);
	}

	for(int i = 0; i < W; i++){
		pthread_join(s[i],NULL);
	}


	return 0;
}
