#include <stdio.h>
#include <math.h>

float task_7(int number , int precision){
    /**
     * Functie care returneaza radacina patrata cu precizie specificata
     * 
     * @param number - numarul al carei rad. patrata va fi calculata
     * @param precision - precizia calcului cu zecimale
     * 
     * @pre number - numar real pozitiv
     * @post se returneaza un string care reprezinta val. rad. patrate a numarului cu 
     *       precizia specificata
     */

    float sq = sqrt(number);
    int sq_w = (int)sq;
    float sq_f = sq - sq_w;
    
    int p = 1;
    for(int i = 0; i < precision; i++){
        sq_f *= 10;
        p *= 10;
    }

    sq_f = (int)sq_f;
    sq_f /= p;

    sq = sq_w + sq_f;
    return sq;
}

int cmmdc(int a, int b){
    /**
     * Functie ce determina cmmdc-ul a 2 numere naturale
     * 
     * @param a(int) - numarul 1
     * @param b(int) - numarul 2
     * 
     * @pre a,b - numere naturale
     * @post se returneaza cmmdc-ul numerelor a si b
     */

    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }

    return a;
}

void task_16(unsigned n){
    /**
     * Functie care printeaza toate numere relativ prime cu n, mai mici decat n
     * 
     * @param n (unsigned) - numarul cu care calculam
     * 
     * @pre n - numar natural
     * @post se afiseaza numerele care sunt relativ prime cu n, mai mici decat n
     */
    printf("The list of relative prime numbers smaller than %u is: " , n);
    for(int i = 1; i < n; i++){
        if(cmmdc(i , n) == 1){
            printf("%d " , i);
        }
    }
    printf("\n");
}


int main(){
    int running = 1;
    int com;
    int j;
    float i;
    unsigned a;
    printf("Welcome to the Lab1 Homework!\n");
    while(running){
        printf("Enter a command (1 - sqrt ; 2 - relative prime ; else - exit)\n>>>");
        scanf("%d" , &com);
        if(com == 1){
            printf("Enter a real number and a precision(ex: 456 3)\n>>>");
            scanf("%f %d" , &i , &j);
            printf("The square root is %.*f\n", j ,task_7(i , j));
        }else if(com == 2){
            printf("Enter a natural number\n>>>");
            scanf("%u" , &a);
            task_16(a);        
        }else{
            running = 0;
        }
    }
    printf("Have a nice day! =)\n");
    return 0;
}