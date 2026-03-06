#include <stdio.h>
#include <stdlib.h>

#define INF 999999

int main(){
    int n;
    int a[100][100] = {0};

    scanf("%d" , &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d" , &a[i][j]);
        }
    }

    //Noduri Izolate
    int ver = 0;
    for(int i = 0; i < n; i++){
        int zc = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                zc = 1;
            }
        }
        if(zc == 0){
            printf("%d e nod izolat\n" , i + 1);
            ver = 1;
        }
    }

    if(ver == 0) printf("Nu exista noduri izolate\n");

    //Graf Regular
    int nr = -1;
    for(int i = 0; i < n; i++){
        int zc = 0;
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                zc++;
            }
        }
        if(nr == -1){
            nr = zc;
        }

        if(nr > -1 && nr != zc){
            printf("Graful nu e regular\n");
            nr = -2;
        }
    }

    if(nr != -2){
        printf("Graful e regular\n");
    }

    // Floyd Warshall

    int d[100][100] = {INF};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            d[i][j] = (a[i][j] == 1) ? 1 : INF;
            if(i == j){
                d[i][j] = 0;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    if(d[i][k] != INF && d[k][j] != INF){
                        d[i][j] = (d[i][j] < d[i][k] + d[k][j]) ? d[i][j] : d[i][k] + d[k][j];
                    }
                }
            }
    }

    printf("\nMatrice Drumurilor:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(d[i][j] != INF){
                printf("%d ",d[i][j]);
            }else{
                printf("∞ ");
            }
        }
        printf("\n");
    }

    // Conexitate
    int con = 1;
    for(int i = 0; i < n; i++){
        if(d[0][i] == INF){
            con = 0;
            break;
        }
    }

    if(con == 1) printf("Graful este conex\n");
    else printf("Graful NU este conex\n");


    return 0;
}