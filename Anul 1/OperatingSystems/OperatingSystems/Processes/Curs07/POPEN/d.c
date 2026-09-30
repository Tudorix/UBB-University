#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	int w2s[2], s2s[2], s2u[2],u2w[2];
	
	pipe(w2s);
	pipe(s2s);
	pipe(s2u);
	pipe(u2w);
	
	if(fork() == 0){
		close(w2s[0]);
		close(s2u[0]);
		close(u2w[0]);

		close(s2s[1]);
		close(s2u[1]);
		close(u2w[1]);
			
		dup2(w2s[1],1);
		
		execlp("who","who",NULL);
		exit(0);
	}
	
	if(fork() == 0){
		close(w2s[0]);
		close(s2s[0]);
		close(u2w[0]);

		close(w2s[1]);
		close(s2s[1]);
		close(u2w[1]);

		dup2(w2s[0])		

		execlp("sed","sed","-E", "s/ .*//", NULL);
		exit(0);
	}
	
	if(fork() == 0){
		close(w2s[0]);
		close(s2s[0]);
		close(s2u[0]);
		close(u2w[0]);

		close(w2s[1]);
		close(s2s[1]);
		close(s2u[1]);
		close(u2w[1]);

		execlp("sort","sort",NULL);
		exit(0);
	}

	if(fork() == 0){
		close(w2s[0]);
		close(s2s[0]);
		close(s2u[0]);
		close(u2w[0]);

		close(w2s[1]);
		close(s2s[1]);
		close(s2u[1]);
		close(u2w[1]);

		execlp("uniq","uniq",NULL);
		exit(0);
	}

	if(fork() == 0){
		close(w2s[0]);
		close(s2s[0]);
		close(s2u[0]);
		close(u2w[0]);

		close(w2s[1]);
		close(s2s[1]);
		close(s2u[1]);
		close(u2w[1]);

		execlp("wc","wc","-l",NULL);
		exit(0);
	}
	
	close(w2s[0]);
	close(s2s[0]);
	close(s2u[0]);
	close(u2w[0]);

	close(w2s[1]);
	close(s2s[1]);
	close(s2u[1]);
	close(u2w[1]);

	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);

	(void) argc;
	(void) argv;
	return 0;
}
