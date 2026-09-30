#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 128

char sir[MAX_SIZE];
int M;
int contor = 0;
int poz_sir = 0;

pthread_cond_t cg = PTHREAD_COND_INITIALIZER;
pthread_cond_t cp = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* generate(void* arg){
	
	while(1){
		
		char chr = 'a' + rand() % ('z' - 'a' + 1);
		pthread_mutex_lock(&mtx);
		if(poz_sir == MAX_SIZE){
			pthread_cond_signal(&cp);
			pthread_cond_wait(&cg,&mtx);
		}


		if(contor == M){
			pthread_mutex_unlock(&mtx);
			break;
		}

		sir[poz_sir] = chr;
		poz_sir++;
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}

void* print(void* arg){
	
	while(1){
		pthread_mutex_lock(&mtx);
		while(poz_sir != MAX_SIZE){
			pthread_cond_wait(&cp,&mtx);
		}

		printf("%s\n",sir);
		memset(sir,0,MAX_SIZE * sizeof(char));
		
		poz_sir = 0;
		contor++;

		pthread_cond_broadcast(&cg);
		if(contor == M){
			pthread_mutex_unlock(&mtx);
			break;
		}
		pthread_mutex_unlock(&mtx);
	}

	return NULL;
}

int main(int argc, char** argv){
	if(argc != 3){
		printf("Nu au fost date argumente!\n");
		exit(1);
	}

	M = atoi(argv[1]);
	int N = atoi(argv[2]);

	pthread_t tg[N];
	for(int i = 0; i < N; i++){
		pthread_create(&tg[i],NULL,generate,NULL);
	}

	pthread_t tp;
	pthread_create(&tp,NULL,print,NULL);
	
	for(int i = 0; i < N; i++){
		pthread_join(tg[i],NULL);
	}
	pthread_join(tp,NULL);

	return 0;
}
