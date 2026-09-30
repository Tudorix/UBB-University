
#define E_GOL 0
#define E_PLIN 1

#define MAX_THR 10
#define MAX_SIZE 100

int buffer[MAX_SIZE];
int suma = 0;
int state = E_GOL;

// Obeicte de sincronizare
pthread_cond_t v_consum = PTHREAD_COND_INITIALIZER , v_producator = PTHREAD_COND_INITIALIZER;
pthrad_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

//Producator
void* produc(void* arg){
	
	pthread_mutex_lock(&mtx);
	while(stare == E_PLIN){
		pthread_cond_wait(&v_producator,&mtx);
	}

	//produc
	for(int i = 0; i < MAX_SIZE; i++){
		buffer[i] = rand() % 256;
	}

	stare = E_PLIN;
	pthread_cond_signal(&v_consumator);
	pthread_mutex_unlock(&mtx);

	return NULL;
}


//Consumator
void* consumator(void* arg){
	
	pthread_mutex_lock(&mtx);
	while(stare == E_PLIN){
		pthread_cond_wait(&v_consumator,&mtx);
	}

	//consum
	for(int i = 0; i < MAX_SIZE;i++){
		suma += buffer[i];
	}

	stare = E_GOL;
	pthread_cond_signal(&v_producator);
	pthread_mutex_unlock(&mtx);

	return NULL;
}


int main(){
	// creez threadurile consumator
	pthread_thread_t tc[MAX_THR];
	for(int i = 0; i < MAX_THR;i++){
		int *idc = malloc(sizeof(int));
		*idc = i;
		pthread_create(&tc[i],NULL,consum,idc);
	}
	//creez threadurile producator
	pthread_thread_t tp[MAX_THR];
	for(int i = 0; i < MAX_THR;i++){
		int *idp = malloc(sizeof(int));
		*idp = i;
		pthread_create(&tp[i],NULL,consum,idp);
	}
	//terminare threaduri
	for(int i = 0; i < MAX_THR;i++){
		pthread_join(&tc[i],NULL);
		pthread_join(&tp[i],NULL);
	}

	printf("%d", suma);

	return 0;
}
