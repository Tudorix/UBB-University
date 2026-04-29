```
Threadul NU dubleaza informatie, primeste doar un buffer de memtorie din stack pt. stackul ei

LIBname.so/a
la compilare ai nev de flagu: -pthread

la GCC: 
-O/O2/O3 - optimizations
-S - gen cod assembly

-> Variable volative C - (de citit)

Spin Lock - consuma procesor verificand cand e in "Pauza"

pthread_mutex_   t,init,destroy,lock, unlock, trylock

pthread_rwlock_ t, init, destroy, rdlock, wrlock, unlock, tryrdlock, trywrlock

pthread_cond_  t,inti,destroy,wait,signal,brodcast

pthread_barrier  t, init, destroy

sem_  t, init, destroy, wait, post

sem_init(&s,NULL,1); <=> pthread_mutex_init(&m,NULL);
-> e la fel ca un mutex cand are val 1

				pthread_mutex_t m;
				pthread_cond_t c;
				int ok = 0;

Astepator                           Desteptator
						     		pthread_mutex_lock(&m);
pthread_mutex_lock(&m);				ok = rand() % 10 - 5;
while(!ok)
	pthread_cond_wait(&c, &m);		if(ok)
pthread_cond_wait(&c,...);              pthread_cond_signal(&c);
									pthread_mutex_unlock(&m);

wait face : unlock mutex, wait signal, lock mutex


se foloseste while deoarece conditia (ok) se poate modifica intre timp
```
