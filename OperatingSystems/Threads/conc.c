#include <stdio.h>
#include <pthread.h>

int n = 1;

void* f(void * a){	
	
	for(int i = 0; i < n; i++){
		printf("%s\n", (char*)a);
	}	

	(void)a;
	return NULL;
}

int main(int argc, char** argv){
	
	if(argc > 1){
		sscanf(argv[1],"%d",&n);
	}
		
	//Init thread
	pthread_t ta,tb;
	
	//Create therad - cu argument
	pthread_create(&ta, NULL, f, "fa");
	pthread_create(&tb, NULL, f, "fb");

	for(int i = 0; i < n; i++){
		printf("main\n");
	}	

	//Kill thread
	pthread_join(ta,NULL);
	pthread_join(tb,NULL);
	
	(void)argv;
	(void)argc;
	return 0;
}
