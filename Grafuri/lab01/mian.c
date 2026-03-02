#include <stdio.h>

struct muchie{
	int x , y;
};

int main(int args, char** argv){
	(void) args;
	
	int n;
	scanf("%d", &n);

	int i , j;
	int index = 0;
	muchie v[100];
	while(scanf("%d %d",&i , &j)){
		muchie[index].x = i;
		muchie[index].y = j;
	}

	return 0;
}
