#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int buffer[4];
// [first, last)
int head = 0, tail = 0;
int empty = 1;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t c = PTHREAD_COND_INITIALIZER;

void* consum(void* arg){
	int m;
	while(1){
		pthread_mutex_lock(&mtx);
		while(empty){
			pthread_cond_wait(&c,&mtx);
		}

			m = buffer[head];
			head++;
			if(head == 4){
				head = 0;
			}

			if(head == tail){
				empty = 1;
			}
			pthread_mutex_unlock(&mtx);
			printf("Consumat %d\n", m);
	}
	return NULL;
}

void* prod(void* arg){
	int cnt = 0;
	while(1){
		pthread_mutex_lock(&mtx);
		if(empty || head != tail){
			empty = 0;
			buffer[tail] = cnt;
			cnt++;
			tail++;
			if(tail == 4){
				tail = 0;
			}
			printf("Produs %d\n", cnt);
			pthread_cond_signal(&c);
		}
		pthread_mutex_unlock(&mtx);
		usleep(500000);
	}
	return NULL;
}


int main(int argc, char** argv){
	
	pthread_t c, p;
	pthread_create(&c,NULL,consum,NULL);
	pthread_create(&p,NULL,prod,NULL);

	pthread_join(c,NULL);
	pthread_join(p,NULL);
	return 0;
}
