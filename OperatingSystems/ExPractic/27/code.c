#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int N,M;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mtx2 = PTHREAD_MUTEX_INITIALIZER;
int ind = 0;
char s[129];
int plin = 0;

pthread_cond_t c = PTHREAD_COND_INITIALIZER;
pthread_cond_t c2 = PTHREAD_COND_INITIALIZER;

void* gen(void* arg){
	
	while(M){
		
		pthread_mutex_lock(&mtx);
		while(plin == 1){
			pthread_cond_wait(&c,&mtx);
		}

		char chr = 'a' + rand() % ('z' - 'a' + 1);
		if(ind < 129){
			s[ind] = chr;
			ind++;
		}else{
			plin = 1;
			pthread_cond_signal(&c2);
		}
		pthread_mutex_unlock(&mtx);
	}
	(void) arg;
	return NULL;
}

void* prt(void* arg){
	
	while(M){
		pthread_mutex_lock(&mtx);

		while(plin == 0){
			pthread_cond_wait(&c2,&mtx);
		}

		printf("%s\n",s);
		for(int i = 0; i < 128;i++){
			s[i] = 0;
		}
		ind = 0;
		M--;
		plin = 0;
		pthread_cond_broadcast(&c);
		pthread_mutex_unlock(&mtx);
	}
	(void) arg;
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc != 3){
		printf("Noob\n");
		return 1;
	}

	N = atoi(argv[1]);
	M = atoi(argv[2]);

	pthread_t t[N], p;
	for(int i = 0; i < N; i++){
		pthread_create(&t[i],NULL,gen,NULL);
	}

	pthread_create(&p,NULL,prt,NULL);

	for(int i = 0; i < N; i++){
		pthread_join(t[i],NULL);
	}

	pthread_join(p,NULL);


	return 0;
}
