#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n;

pthread_mutex_t *mtx;
pthread_barrier_t b;

void* func(void* arg){
	int id = *((int*)arg);
	free(arg);

	if(id % 4 == 0){
		pthread_barrier_wait(&b);	
	}

	while(1){
		if(id % 4 == 0){
			usleep(500000);
			printf("Threadul 1 din echipa %d e gata\n",(int)(id / 4 + 1));
			pthread_mutex_unlock(&mtx[id + 1]);
			break;
		}else if (id % 4 == 1){			
			pthread_mutex_lock(&mtx[id]);
			usleep(500000);
			printf("Threadul 2 din echipa %d e gata\n",(int)(id / 4 + 1));
		    pthread_mutex_unlock(&mtx[id + 1]);
			break;
		}else if (id % 4 == 2){			
			usleep(500000);
			pthread_mutex_lock(&mtx[id]);
			printf("Threadul 3 din echipa %d e gata\n",(int)(id / 4 + 1));
		    pthread_mutex_unlock(&mtx[id + 1]);
			break;
		}else if (id % 4 == 3){			
			pthread_mutex_lock(&mtx[id]);
			usleep(500000);
			printf("Echipa %d a terminat!\n",(int)(id / 4 + 1));
			break;
		}
	}
	return NULL;
}

int main(){
	scanf("%d",&n);

	pthread_t t[n * 4];
	mtx = malloc(sizeof(pthread_mutex_t) * (4 * n));
	
	pthread_barrier_init(&b,NULL,n);
	for(int i = 0; i < n * 4; i++){
		pthread_mutex_init(&mtx[i], NULL);
		if(i % 4 != 0)
			pthread_mutex_lock(&mtx[i]);
	}

	for(int i = 0; i < 4 * n; i++){
		int *id = malloc(sizeof(int));
		*id = i;
		pthread_create(&t[i],NULL,func,id);
	}

	for(int i = 0; i < 4 * n; i++){
		pthread_join(t[i],NULL);
		pthread_mutex_destroy(&mtx[i]);
	}
	pthread_barrier_destroy(&b);

	return 0;

}

