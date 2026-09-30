#include <stdio.h>
#include <stdlib.h>

struct Muchie{
	int a;
	int b;
	int n;
};

int main(){
	int n, v = 0;
	scanf("%d", &n);
	
	int i , j;
	int k = 0;
	struct Muchie m[100];
	
	for(k = 0; k < n; k++){
		scanf("%d %d",&i , &j);
		m[k].a = i;
		m[k].b = j;
		m[k].n = k;
		if(i > v) v = i;
		if(j > v) v = j;
	}

	//Matrice de adiacenta--------------------------------------------------------------
	int **a =(int**) malloc(v * sizeof(int*));
	for(i = 0; i < v; i++){
		a[i] =(int*) malloc(v * sizeof(int));
		for(j = 0; j < v; j++){
			a[i][j] = 0;
		}
	}

	for(i = 0; i < n; i++){
		a[m[i].a - 1][m[i].b - 1] = 1;
		a[m[i].b - 1][m[i].a - 1] = 1;
	}

	printf("Matricea de adiacenta:\n");
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// Lista de adiacenta----------------------------------------------------
	int **b = (int**)malloc(v * sizeof(int*));
	for(i = 0; i < v; i++){
		b[i] = (int*)malloc((n + 1) * sizeof(int));
		for(j = 0; j <= n; j++){
			b[i][j] = 0;
		}
	}		

	printf("\nLista de adiacenta:\n");
	for(i = 0; i < v; i++){
		int k = 0;
		for(j = 0; j < v; j++){
			if(a[i][j] == 1){
				b[i][k] = j + 1;
				k++;
			}
		}
	}

	// Free the memory
	for(i = 0; i < v; i++){
		free(a[i]);
	}
	free(a);
	
	for(i = 0; i < v; i++){
		printf("%d: ", i + 1);
		for(j = 0; j <= n; j++){
			if(b[i][j] != 0)
				printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	//Matrice de incidenta------------------------------------------------------------
	int **c = (int**)malloc(v * sizeof(int*));
	for(i = 0; i < v; i++){
		c[i] = (int*)malloc(n * sizeof(int));
		for(j = 0; j < n; j++){
			c[i][j] = 0;
		}
	}

	for(i = 0; i < v; i++){
		for(j = 0; j < n; j++){
			if(b[i][j] != 0){
				int nrMuchie = 0;
				for(k = 0; k < n; k++){
					if(m[k].a == i + 1 && m[k].b == b[i][j]){
						nrMuchie = m[k].n;
						c[i][nrMuchie] = 1;
						c[b[i][j] - 1][nrMuchie] = 1;
						break;
					}
				}
			}
		}
	}

	printf("\nMatrice de incidenta:\n");
	for(i = 0; i < v; i++){
		for(j = 0; j < n; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < v; i++){
		free(b[i]);
	}
	free(b);

	//Lista de adiacenta--------------------------------------------
	b = (int**)malloc(v * sizeof(int*));
	for(i = 0; i < v; i++){
		b[i] = (int*)malloc(n * sizeof(int));
		for(j = 0; j < n; j++){
			b[i][j] = 0;
		}
	}	

	for(j = 0; j < n; j++){
		int s = -1, d = -1;
		for(i = 0; i < v; i++){
			if(c[i][j] == 1 && s == -1) s = i;
			else if(c[i][j] == 1 && s != -1) d = i;
			if(s != -1 && d != -1){
				int p = 0;
				while(b[s][p] != 0) p++;
				b[s][p] = d + 1;

				p = 0;
				while(b[d][p] != 0) p++;
				b[d][p] = s + 1;
				break;
			}
		}
	}

	printf("\nLista de adiacenta:\n");
	for(i = 0; i < v; i++){
		printf("%d: ", i + 1);
		for(j = 0; j < n; j++){
			if(b[i][j] != 0)
				printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < v; i++){
		free(c[i]);
	}
	free(c);

	//Matrice adiacenta ---------------------------------------
	a =(int**) malloc(v * sizeof(int*));
	for(i = 0; i < v; i++){
		a[i] =(int*) malloc(v * sizeof(int));
		for(j = 0; j < v; j++){
			a[i][j] = 0;
		}
	}

	for(i = 0; i < v; i++){
		for(j = 0; j < n; j++){
			if(b[i][j] != 0)
				a[i][b[i][j] - 1] = 1;
		}
	}

	printf("\nMatricea de adiacenta:\n");
	for(i = 0; i < v; i++){
		for(j = 0; j < v; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < v; i++){
		free(b[i]);
	}
	free(b);

	c = malloc(n * sizeof(int*));
	for(i = 0; i < n; i++){
		c[i] = malloc(2 * sizeof(int));
		for(j = 0; j < 2; j++){
			c[i][j] = 0;
		}
	}

	k = 0;
	for(i = 0; i < v; i++){
		for(j = i; j < v; j++){
			if(a[i][j] != 0){
				c[k][0] = i + 1;
				c[k][1] = j + 1;
				k++;
			}
		}
	}

	printf("\nLista de Muchii:\n");
	for(i = 0; i < n; i++){
		for(j = 0; j < 2; j++){
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}

	for(i = 0; i < v; i++){
		free(a[i]);
	}
	free(a);

	for(i = 0; i < n; i++){
		free(c[i]);
	}
	free(c);

	return 0;
}