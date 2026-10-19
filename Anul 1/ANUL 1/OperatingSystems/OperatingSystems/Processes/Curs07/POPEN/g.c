#include <stdio.h>
#include "e.h"
#include <sys/shm.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>


int main(){
	int shmid;

	struct absp *x;

	shmid = shmget(1234,0,0);
	x = shmat(shmid,0,0);

	srand(time(NULL));
	while(1){
		x->s = x->a + x->b;
		x->p = x->a * x->b;
		if(x->s == x->p) break;
	}	

	shmdt(x);

	return 0;
}
