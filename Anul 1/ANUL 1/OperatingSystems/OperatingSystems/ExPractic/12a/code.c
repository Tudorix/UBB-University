#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int n, m;
int a[105][105];
int sum = 0;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* func(void* arg){
	int* id = (int*)arg;
	int ls = 0;
	for(int i = 0; i < m; i++){
		ls += a[*id][i];
	}

	pthread_mutex_lock(&mtx);
	sum += ls;
	pthread_mutex_unlock(&mtx);
	
	return NULL;
}

int main(){
	FILE *f;

	f = fopen("input.in","r");

	if(f == NULL){
		printf("Error in opening file\n");
		return 1;
	}

	fscanf(f ,"%d %d", &n, &m);
	printf("n=%d\n", n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			fscanf(f, "%d",&a[i][j]);
		}
	}

	fclose(f);

	// Threaduri
	pthread_t t[n];

	for(int i = 0; i < n; i++){
		int* id = malloc(sizeof(int));
		*id = i;
		pthread_create(&t[i],NULL,func,id);
	}

	for(int i = 0; i < n; i++){
		pthread_join(t[i],NULL);
	}

	printf("%d", sum);

	return 0;
}
