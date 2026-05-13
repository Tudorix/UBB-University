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
	struct Args y;
	pthread_t t2;
	pthread_t t1;

	int a,b;
	sscanf(argv[1],"%d", &a);
	sscanf(argv[2],"%d", &b);

	x.a = a;
	x.b = (a + b) / 2;
	y.a= x.b + 1;
	y.b = b;

	int count = 0;
	
	pthread_create(&t1,NULL,func,&x);
	pthread_create(&t2,NULL,func,&y);
	int *rez1 , *rez2;
	int ret;
	pthread_join(t1,(void**)&rez1);
	pthread_join(t2,(void**)&rez2);
	ret = *rez1 + *rez2;
	printf("%d\n", ret);
	free(rez1);
	free(rez2);
	return 0;
}
