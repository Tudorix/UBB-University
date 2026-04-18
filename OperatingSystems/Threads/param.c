#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int n = 1;

void* f(void * a){	
	printf("%d\n", *(int*)a);
	free(a);

	(void)a;
	return NULL;
}

int main(int argc, char** argv){
	//Init thread
	pthread_t t[10];

	//Create therad - parametrii
	for(int i = 0; i < 10; i++){
		int *a = (int*)malloc(sizeof(int));
		*a = i;
		pthread_create(&t[i], NULL, f, a);
	}

	//Kill thread
	for(int i = 0; i < 10; i++)
		pthread_join(t[i],NULL);
	
	(void)argv;
	(void)argc;
	return 0;
}
