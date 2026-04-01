#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){
	int n;

	FILE *f = popen("who | sed -E 's/ .*//' | sort | uniq | wc -l","r");
	fscanf(f,"%d",&n);
	pclose(f);

	printf("%d \n", n);
	(void) argc;
	(void) argv;
	return 0;
}
