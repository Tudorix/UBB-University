#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int s = 0;
    char x[50];

    printf("Numerele sunt:");
    fgets(x , 50 , stdin);

    //String edit
    char *p;
    p = strtok(x , " ");
    while(p){
        s += atoi(p);
        p = strtok(NULL , " ");
    }

    printf("Suma numerelor este %d \n" , s);
    return 0;
}