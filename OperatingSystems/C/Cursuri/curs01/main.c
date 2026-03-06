#include <stdio.h>
#include <string.h>
#include <unistd.h>

void withLib(){
	char s[64];
	char *p;

	while(1){
		p = fgets(s , 64, stdin);
		if(p == NULL) break;

		for(int i = 0; i < (int)strlen(s); i++){
			if(s[i] != '\n'){
				s[i] = '*';
			}
		}
		fputs(s,stdout);
	}
}

void withSys(){
	char s[64];

	while(1){
		int k = read(0, s, 64);
		if(k <= 0) break;

		for(int i = 0; i < k; i++){
			if(s[i] != '\n'){
				s[i] = '*';
			}
		}
		write(1,s,k);
	}
}

int main(int args, char** argv){
	(void)args; // Nr de argumente
	(void)argv; // Argumentele
	//withLib();
	//withSys();

	if(args > 1 && strcmp("lib", argv[1])==0){
		withLib();
	}else if(args > 1 && strcmp("sys", argv[1])==0){
		withSys();
	}else{
		fputs("Argument necunoscut",stderr);
	}
	return 0;
}
