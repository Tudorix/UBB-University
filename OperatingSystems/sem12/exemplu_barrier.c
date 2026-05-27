

pthread_barrier_t barr;

void* do_smth(void* arg){
	//	CALCULE ETAPA 1
	pthread_barrier_wait(&barr);
	//	CALC ETAPA 2
}

int main(){
	//	INIT BARIERA
	pthread_barrier_init(&barr,NULL,50);
	//	CREEZU THREADURI


	pthread_barrier_destroy(&barr);
}
