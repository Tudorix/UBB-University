#include <stdio.h>
#include <pthread.h>

void* f(void * a){
	printf("f\n");
	(void)a;
	return NULL;
}

int main(int argc, char** argv){
	(void)argc;
	(void)argv;

	//Init thread
	pthread_t t;
	
	//Create therad
	pthread_create(&t, NULL, f, NULL);
	printf("main\n");

	//Kill thread
	pthread_join(t,NULL);
	
	return 0;
}
