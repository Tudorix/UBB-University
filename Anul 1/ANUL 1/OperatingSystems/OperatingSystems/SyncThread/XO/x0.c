#include <stdio.h>
#include <pthread.h>

int m[3][3] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
pthread_mutex_t mx, m0;

void* fx(void* a){
	int i, j;
	while(1){
		int played = 0;
		pthread_mutex_lock(&mx);
		for(i = 0; i<3; i++){
			for(j = 0; j < 3; j++)	{
				if(m[i][j] == -1 && !played){
					m[i][j] = 1;
					played = 1;
				}
			}
		}
		pthread_mutex_unlock(&m0);
		if(!played) break;
	}
	
	(void)a;
	return NULL;
}


void* f0(void* a){
	int i, j;
	while(1){
		int played = 0;
		pthread_mutex_lock(&m0);
		for(i = 0; i<3; i++){
			for(j = 0; j < 3; j++)	{
				if(m[i][j] == -1 && !played){
					m[i][j] = 1;
					played = 1;
				}
			}
		}
		pthread_mutex_unlock(&mx);
		if(!played) break;
	}
	
	(void)a;
	return NULL;
}

int main(){
		
	pthread_t tx, t0;
	pthread_mutex_init(&mx,NULL);
	pthread_mutex_init(&m0,NULL);

	pthread_mutex_lock(&m0);

	pthread_create(&tx,NULL,fx,NULL);
	pthread_create(&t0,NULL,f0,NULL);

	pthread_join(tx, NULL);
	pthread_join(t0, NULL);

	pthread_mutex_destroy(&mx);
	pthread_mutex_destroy(&m0);
	return 0;
}






