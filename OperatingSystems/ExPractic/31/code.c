#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n;
int primu;
pthread_barrier_t b;
int found = 0;
int count_print = 0;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *func(void* arg){
	pthread_barrier_wait(&b);
	int nr;
	while(1){	
		nr = rand() % 111111;
		pthread_mutex_lock(&mtx);
		
		if(found == 1){
			count_print++;
			pthread_mutex_unlock(&mtx);
			break;
		}

		if(nr % 1001 == 0){
			found = 1;
			primu = nr;
			pthread_mutex_unlock(&mtx);
			pthread_barrier_wait(&b);
			printf("Primu este : %d\n",nr);
			return NULL;
		}
		pthread_mutex_unlock(&mtx);
	}
	printf("%d\n",nr);
	pthread_barrier_wait(&b);
	(void) arg;
	return NULL;
}

int main(){
	scanf("%d",&n);
	pthread_barrier_init(&b,NULL, n);
	srand(time(NULL));	
	pthread_t t[n];
	for(int i = 0; i < n; i++){
		pthread_create(&t[i],NULL,func,NULL);
	}

	for(int i = 0; i < n; i++){
		pthread_join(t[i],NULL);
	}

	//printf("Primu a fost : %d\n", primu);

	pthread_barrier_destroy(&b);
	return 0;
}
