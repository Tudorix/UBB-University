#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int n;
pthread_barrier_t b;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
FILE *f;
int gol = 0;

void* func(void* arg){
    char* buffer = NULL;
    int size = 0;
	(void) arg;
    while(1){
        pthread_barrier_wait(&b);
		pthread_mutex_lock(&mtx);

        if(gol == 0){
            int nr = 1 + rand() % 3;

            for(int i = 0; i < nr; i++){
                char cuv[21];

                int ver = fscanf(f, "%20s", cuv);

                if(ver != 1){
                    gol = 1;
                    break;
                }

                int len = strlen(cuv);
                char *nou = realloc(buffer, size + len + 2);
                if(nou == NULL){
                    free(buffer);
                    pthread_mutex_unlock(&mtx);
                    return NULL;
                }

                buffer = nou;

                memcpy(buffer + size, cuv, len);
                size += len;

                buffer[size++] = ' ';
                buffer[size] = '\0';
            }
        }

        pthread_mutex_unlock(&mtx);
		
		pthread_barrier_wait(&b);

        pthread_mutex_lock(&mtx);
        int stop = gol;
        pthread_mutex_unlock(&mtx);

        if(stop)
            break;
    }

    return buffer;
}

int main(int nr, char** a){
	srand(time(NULL));	
	if(nr < 2) return 1;
	n = atoi(a[1]);

	f = fopen("input.txt","r");

	pthread_barrier_init(&b, NULL, n);
	pthread_t t[n];
	for(int i = 0 ; i < n; i++){
		pthread_create(&t[i],NULL,func,NULL);
	}

	for(int i = 0; i < n; i++){
		char *rez = NULL;
		pthread_join(t[i], (void**)&rez);

		if(rez != NULL) {
    		printf("%s\n", rez);
    		free(rez);
		}
	}
	printf("gata\n");
	pthread_barrier_destroy(&b);
	fclose(f);

	return 0;
}	
