#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int e_prim(int nr){
	for(int i = 2; i * i <= nr; i++){
		if(nr % i == 0) return 0;
	}

	return 1;
}

struct Args{
	int a, b;
};

void* func(void* arg){
	struct Args* x = (struct Args*)arg;
	int a = x->a;
	int b = x->b;

	int count = 0;
	for(int i = a; i <= b; i++){
		if(e_prim(i)) count++;
	}

	int *ret = (int*) malloc(sizeof(int)); 
	*ret = count;
	return ret;
	(void) arg;
}

int main(int argc, char** argv){
	struct Args x;
	pthread_t t;

	sscanf(argv[1],"%d", &x.a);
	sscanf(argv[2],"%d", &x.b);
	
	pthread_create(&t,NULL,func,&x);
	int *ret;
	pthread_join(t,(void**)&ret);
	printf("%d\n", *ret);
	free(ret);
	return 0;
}
