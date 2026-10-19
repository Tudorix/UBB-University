#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int n = 0;
pthread_mutex_t m;

void* f(void * a){	
	for(int i = 0; i < 1; i++){
		pthread_mutex_lock(&m);
		n += *(int*)a;
		pthread_mutex_unlock(&m);
	}
	return NULL;
}

int main(int argc, char** argv){
	//Init thread
	pthread_t t[10];
	int k;

	if(argc > 1){
		sscanf(argv[1],"%d",&k);
	}

	pthread_mutex_init(&m,NULL);

	//Create therad - parametrii
	for(int i = 0; i < 10; i++){
		pthread_create(&t[i], NULL, f, &k);
	}

	//Kill thread
	for(int i = 0; i < 10; i++)
		pthread_join(t[i],NULL);
	
	pthread_mutex_destroy(&m);
	printf("%d\n",n);	
	(void)argv;
	(void)argc;
	return 0;
}
