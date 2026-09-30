#include <stdio.h>
#include "e.h"
#include <sys/types.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int shmid;

	struct absp *x;

	shmid = shmget(1234,sizeof(struct absp),IPC_CREAT | 0600);
	x = shmat(shmid,0,0);

	srand(time(NULL));
	while(1){
		x->a = rand();
		x->b = rand();
		if(x->s == x->p) break;
	}	

	shmdt(x);
	shmctl(shmid,IPC_RMID,NULL);

	return 0;
}
