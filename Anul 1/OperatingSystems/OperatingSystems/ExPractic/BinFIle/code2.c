#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

FILE *f;
int v[100] = {-1};
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int e_gol = 0;

int vg = 1;
int sum = 0;
int count = 1000;

void* crt(void* arg){
	
	while(1){
		pthread_mutex_lock(&mtx);
			
		if(vg == 0){
			for(int i = 0; i < 100; i++){
				sum += v[i];
			}
			vg = 1;
		}
		
		if(count <= 0) {
			pthread_mutex_unlock(&mtx);
			break;
		}
		pthread_mutex_unlock(&mtx);
	}
	(void)arg;
	return NULL;
}


void* prd(void* arg){
	int x;
	while(1){
		pthread_mutex_lock(&mtx);
		
		if(count <= 0) {
			pthread_mutex_unlock(&mtx);
			break;
		}

		if(vg == 1){
			for(int i = 0; i < 100; i++){
				if(fread(&x,sizeof(int),1,f) == 1){
					v[i] = x;	
				}
			}
		}
		
		vg = 0;
		count-= 100;

		pthread_mutex_unlock(&mtx);
	}
	(void) arg;
	return NULL;
}

int main(){
	
	f = fopen("input.bin","r");

	pthread_t c[10], p[10];

	for(int i = 0; i < 10; i++){
		pthread_create(&c[i],NULL,crt,NULL);
		pthread_create(&p[i],NULL,prd,NULL);
	}
	
	for(int i = 0; i < 10; i++){
		pthread_join(c[i],NULL);
		pthread_join(p[i],NULL);
	}
	
	printf("%d\n",sum);

	fclose(f);
	return 0;
}
