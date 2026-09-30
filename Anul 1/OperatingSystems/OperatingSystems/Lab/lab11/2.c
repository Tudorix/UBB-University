#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int e_prim(int nr){
	for(int i = 2; i * i <= nr; i++){
		if(nr % i == 0) return 0;
	}

	return 1;
}

struct Args{
	int a, b;
	int id; // Val de dispersie
};

const int T = 100;
int ret;
pthread_mutex_t mtx;

void* func(void* arg){
	struct Args* x = (struct Args*)arg;

	int count = 0;
	for(int i = x->a + x->id; i <= x->b; i += T){
		if(e_prim(i)){
			pthread_mutex_lock(&mtx);
			ret++;
			pthread_mutex_unlock(&mtx);

		}
	}
	
	return 0;
}

int main(int argc, char** argv){
	
	int a, b;
	sscanf(argv[1],"%d", &a);
	sscanf(argv[2],"%d", &b);

	pthread_mutex_init(&mtx,NULL);

	pthread_t t[T];
	struct Args ar[T];
	for(int i = 0; i < T; i++){
		ar[i].id = i;
		ar[i].a = a;
		ar[i].b = b;
		pthread_create(&t[i], NULL, func,&ar[i]);
	}

	for(int i = 0; i < T; i++){
		pthread_join(t[i],NULL);
	}

	pthread_mutex_destroy(&mtx);

	printf("Numar : %d\n", ret);
	return 0;
}
