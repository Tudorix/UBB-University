#include "cheltuiala.h"
#include "teste.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "stack.h"
#include "repo.h"

int main() {

    stack *s = initStack();  

    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    int rasp = test_all();
    
    load(&cheltuieli,s,"/home/tudorix/UBB/UBB-University/OOP/Lab5/save.txt");

    if (rasp == 0) {
        printf("Testele a esuat\n");
    } else {
        meniu(&cheltuieli, s);
    }

    save(&cheltuieli,"/home/tudorix/UBB/UBB-University/OOP/Lab5/save.txt");

    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    destroy(s);

    return 0;
}