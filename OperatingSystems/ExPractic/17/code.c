#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;
int ind = 0;

pthread_mutex_t mp = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mi = PTHREAD_MUTEX_INITIALIZER;

void* impar(void* arg){
	int *x = (int*)arg;
	
	while(N > 0){
	int c = rand() % 100;
	while(c % 2 == 0) {
		c = rand() % 100;
	}
	pthread_mutex_lock(&mi);
	x[ind] = c;
	ind++;
	N--;
	pthread_mutex_unlock(&mp);
	}
	(void) x;
	return NULL;
}

void* par(void* arg){
	int *x = (int*)arg;
	while(N > 0){
	int c = rand() % 100;
	while(c % 2 != 0) {
		c = rand() % 100;
	}
	pthread_mutex_lock(&mp);
	x[ind] = c;
	ind++;
	N--;
	pthread_mutex_unlock(&mi);
	}
	(void) x;
	return NULL;
}

int main(int argc, char** argv){
	if(argc != 2){
		exit(1);
	}
	
	srand(time(NULL));
	N = atoi(argv[1]);
	int n = N;

	pthread_t tp,ti;
	int *a = malloc(sizeof(int) * N);

	pthread_mutex_lock(&mi);

	pthread_create(&tp,NULL,par,a);
	pthread_create(&ti,NULL,impar,a);

	pthread_join(tp,NULL);
	pthread_join(ti,NULL);

	for(int i = 0 ; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}
