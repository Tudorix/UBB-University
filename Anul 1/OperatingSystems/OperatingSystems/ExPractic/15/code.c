#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct info{
	int c, l, s;
	pthread_mutex_t mc;
	pthread_mutex_t ml;
	pthread_mutex_t ms;
};

struct argum{
	struct info* ref;
	char* st;
};

void* func(void* arg){
	struct argum *a = (struct argum*)arg;
	
	for(long unsigned int i = 0; i < strlen(a->st); i++){
		if(a->st[i] >= '0' && a->st[i] <= '9'){
			pthread_mutex_lock(&a->ref->mc);
			a->ref->c++;
			pthread_mutex_unlock(&a->ref->mc);
		}
	}

	(void) a;
	return NULL;
}

int main(int argc, char** argv){
	if(argc < 2){
		printf("Nu\n");
		exit(1);
	}

	pthread_t t[argc - 1];
	pthread_mutex_t mtx_c = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t mtx_l = PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t mtx_s = PTHREAD_MUTEX_INITIALIZER;

	struct info *fin = malloc(sizeof(struct info));
	fin->c = 0;
	fin->l = 0;
	fin->s = 0;
	fin->mc = mtx_c;
	fin->ml = mtx_l;
	fin->ms = mtx_s;

	struct argum *a = malloc(sizeof(struct argum) * (argc - 1));
	
	for(int i = 0; i < argc - 1; i++){
		a[i].ref = fin;
		a[i].st = argv[i + 1];
		pthread_create(&t[i],NULL,func,&a[i]);
	}

	for(int i = 0; i < argc - 1; i++){
		pthread_join(t[i],NULL);
	}

	printf("cifre = %d\n", fin->c);

	free(fin);
	free(a);

	(void) argv;
	return 0;	
}
