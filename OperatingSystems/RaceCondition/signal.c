#include <stdio.h>
#include <signal.h>

void f(int sgn){
	printf("ha ha nu vreau\n");
}

int main(int argc, char** argv){
	signal(SIGINT,f);
	while(1);
	(void)argc;
	(void)argv;
	return 0;
}
