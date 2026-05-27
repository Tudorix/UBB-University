#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *f;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int gol = 0;

void* func(void* arg){
	int r = 0;
	while(1){
		pthread_mutex_lock(&mtx);
		if(gol == 1){
			pthread_mutex_unlock(&mtx);
			break;
		}

		int x;
		if(fread(&x,sizeof(int),1,f) == 1){
			if(x % 5 == 0) r += 1; 
		}else{
			gol = 1;
			pthread_mutex_unlock(&mtx);
			break;
		}
		pthread_mutex_unlock(&mtx);
	}

	(void)arg;
	int* rez = malloc(sizeof(int));
	*rez = r;
	return rez;
}

int main(){
	f = fopen("input.bin","r");
	
	pthread_t t[100];

	for(int i = 0; i < 100; i++){
		pthread_create(&t[i],NULL,func,NULL);
	}
	
	int count = 0;
	for(int i = 0; i < 100; i++){
		int* ret = NULL;
		pthread_join(t[i],(void**)&ret);
		count += *ret;
		free(ret);
	}

	printf("%d\n",count);

	fclose(f);
	return 0;
}
