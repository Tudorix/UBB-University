#include <stdio.h>
#include <stdlib.h>

struct example{
	int var1;
};

int main(int args, char** argv){
	(void)args;
	(void)argv;

 	char *sir = malloc(100 * sizeof(char));	
	free(sir);
	exit(0);
}
