#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int n;
FILE *f;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t b;
int gata = 0;

void* func(void* arg) {
    char *buffer = malloc(1);
    buffer[0] = '\0';

    int len = 0;

    while (1) {
        int local_gata = 0;

        pthread_mutex_lock(&mtx);

        if (!gata) {
            int k = 1 + rand() % 3;

            for (int i = 0; i < k; i++) {
                char word[21];

                if (fscanf(f, "%20s", word) != 1) {
                    gata = 1;
                    break;
                }

                int word_len = strlen(word);

                char *new_buffer = realloc(buffer, len + word_len + 2);
                if (new_buffer == NULL) {
                    free(buffer);
                    pthread_mutex_unlock(&mtx);
                    return NULL;
                }

                buffer = new_buffer;

                strcpy(buffer + len, word);
                len += word_len;

                buffer[len++] = ' ';
                buffer[len] = '\0';
            }
        }

        local_gata = gata;

        pthread_mutex_unlock(&mtx);

        pthread_barrier_wait(&b);

        if (local_gata)
            break;
    }

    return buffer;
}

int main(int argc, char** argv){
	
	if(argc < 2){
		printf("Not enough args!");
		exit(1);
	}

	n = atoi(argv[1]);
	f = fopen("input.txt","r");
	pthread_barrier_init(&b,NULL,n);
	
	pthread_t t[n];
	for(int i = 0; i < n; i++){
		pthread_create(&t[i],NULL,func,NULL);
	}

	for(int i = 0; i < n; i++){
		char *rez = NULL;
		pthread_join(t[i], (void**)&rez);
		printf("%s\n", rez);
		free(rez);
	}

	pthread_barrier_destroy(&b);
	fclose(f);
	return 0;
}
