#include "teste.h"
#include "service.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//##### L5
void test_stack(){
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    stack *s = initStack();

    push(&cheltuieli,s);
    adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    push(&cheltuieli,s);
    adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    push(&cheltuieli,s);
    adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    assert(s->len == 3);

    push(&cheltuieli,s);
    sterge_cheltuiala(&cheltuieli,1);
    assert(s->len == 4);

    pop(s);
    pop(s);
    assert(s->len == 2);

    pop(s);
    pop(s);
    pop(s);
    assert(s->len == 0);

    //Free memory
    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    destroy(s);
}

int test_adauga_cheltuiala() {
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    int res = adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    if (res == 0) {
        printf("Test adauga_cheltuiala a esuat\n");
        return 0;
    }
    if (cheltuieli.len != 1) {
        printf("Test adauga_cheltuiala a esuat\n");
        return 0;
    }
    if (cheltuieli.cheltuieli[0].id != 1 || cheltuieli.cheltuieli[0].zi != 10 || cheltuieli.cheltuieli[0].suma != 100 || strcmp(cheltuieli.cheltuieli[0].tip, "mancare") != 0) {
        printf("Test adauga_cheltuiala a esuat\n");
        return 0;
    }
    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    return 1;
}

int test_modifica_cheltuiala() {
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    int res = modifica_cheltuiala(&cheltuieli, 1, 15, 150, "transport");
    if (res == 0) {
        printf("Test modifica_cheltuiala a esuat\n");
        return 0;
    }
    if (res == -1) {
        printf("Test modifica_cheltuiala a esuat\n");
        return 0;
    }
    if (cheltuieli.cheltuieli[0].id != 1 || cheltuieli.cheltuieli[0].zi != 15 || cheltuieli.cheltuieli[0].suma != 150 || strcmp(cheltuieli.cheltuieli[0].tip, "transport") != 0) {
        printf("Test modifica_cheltuiala a esuat\n");
        return 0;
    }
    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    return 1;
}

int test_sterge_cheltuiala() {
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    int res = sterge_cheltuiala(&cheltuieli, 1);
    if (res == 0) {
        printf("Test sterge_cheltuiala a esuat\n");
        return 0;
    }
    if (res == -1) {
        printf("Test sterge_cheltuiala a esuat\n");
        return 0;
    }
    if (cheltuieli.len != 0) {
        printf("Test sterge_cheltuiala a esuat\n");
        return 0;
    }
    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    return 1;
}

// int test_cauta_cheltuiala_dupa_tip() {
//     Lista cheltuieli;
//     cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
//     cheltuieli.len = 0;
//     cheltuieli.cap = 10;

//     adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
//     char *tip = "mancare";
//     int res = cauta_cheltuiala_dupa_tip(&cheltuieli, tip);
//     if (res == 0) {
//         printf("Test cauta_cheltuiala_dupa_tip a esuat\n");
//         return 0;
//     }

//     tip = "man";
//     res = cauta_cheltuiala_dupa_tip(&cheltuieli, tip);
//     if (res == 0) {
//         printf("Test cauta_cheltuiala_dupa_tip a esuat\n");
//         return 0;
//     }
//     return 1;
// }

int test_cauta_cheltuieli() {
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    adauga_cheltuiala(&cheltuieli, 10, 100, "mancare");
    adauga_cheltuiala(&cheltuieli, 11, 200, "transport");
    adauga_cheltuiala(&cheltuieli, 10, 300, "mancare");

    struct OptiuniCautaCheltuieli optiuni;
    optiuni.suma = 0;
    optiuni.zi = 10;
    optiuni.tip = "";
    optiuni.cheltuieli = malloc(cheltuieli.len * sizeof(Cheltuiala));
    optiuni.nr_cheltuieli = 0;

    cauta_cheltuieli(&cheltuieli, &optiuni);

    if (optiuni.nr_cheltuieli != 2) {
        printf("Test cauta_cheltuieli a esuat\n");
        free(optiuni.cheltuieli);
        return 0;
    }

    free(optiuni.cheltuieli);

    optiuni.suma = 200;
    optiuni.zi = 0;
    optiuni.tip = "transport";
    optiuni.cheltuieli = malloc(cheltuieli.len * sizeof(Cheltuiala));
    optiuni.nr_cheltuieli = 0;

    cauta_cheltuieli(&cheltuieli, &optiuni);

    if (optiuni.nr_cheltuieli != 1) {
        printf("Test cauta_cheltuieli a esuat\n");
        free(optiuni.cheltuieli);
        return 0;
    }

    free(optiuni.cheltuieli);
    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    return 1;
}

//##### L5
int test_filt_dupa_zi() {
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    adauga_cheltuiala(&cheltuieli, 10, 300, "transport");
    adauga_cheltuiala(&cheltuieli, 11, 100, "mancare");
    adauga_cheltuiala(&cheltuieli, 12, 200, "altele");
    adauga_cheltuiala(&cheltuieli, 13, 100, "altele");

    int len;
    Cheltuiala* sortate = filtarare_dupa_zi(&cheltuieli, 1, &len);
    assert(len == 0);
    free(sortate);

    sortate = filtarare_dupa_zi(&cheltuieli, 10, &len);
    assert(len == 1);
    free(sortate);

    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    return 1;
}



int test_sorteaza_cheltuieli() {
    Lista cheltuieli;
    cheltuieli.cheltuieli = malloc(10 * sizeof(Cheltuiala));
    cheltuieli.len = 0;
    cheltuieli.cap = 10;

    adauga_cheltuiala(&cheltuieli, 10, 300, "transport");
    adauga_cheltuiala(&cheltuieli, 11, 100, "mancare");
    adauga_cheltuiala(&cheltuieli, 12, 200, "altele");
    adauga_cheltuiala(&cheltuieli, 13, 100, "altele");

    Cheltuiala* sortate = sorteaza_cheltuieli(&cheltuieli, 1, 0);
    if (sortate[0].suma != 100 || sortate[1].suma != 100 || sortate[2].suma != 200 || sortate[3].suma != 300) {
        printf("Test sorteaza_cheltuieli (suma crescator) a esuat\n");
        free(sortate);
        return 0;
    }
    free(sortate);

    sortate = sorteaza_cheltuieli(&cheltuieli, -1, 0);
    if (sortate[0].suma != 300 || sortate[1].suma != 200 || sortate[2].suma != 100 || sortate[3].suma != 100) {
        printf("Test sorteaza_cheltuieli (suma descrescator) a esuat\n");
        free(sortate);
        return 0;
    }
    free(sortate);

    sortate = sorteaza_cheltuieli(&cheltuieli, 0, 1);
    if (strcmp(sortate[0].tip, "altele") != 0 || strcmp(sortate[1].tip, "altele") != 0 || strcmp(sortate[2].tip, "mancare") != 0 || strcmp(sortate[3].tip, "transport") != 0) {
        printf("Test sorteaza_cheltuieli (tip crescator) a esuat\n");
        free(sortate);
        return 0;
    }
    free(sortate);

    sortate = sorteaza_cheltuieli(&cheltuieli, 0, -1);
    if (strcmp(sortate[0].tip, "transport") != 0 || strcmp(sortate[1].tip, "mancare") != 0 || strcmp(sortate[2].tip, "altele") != 0 || strcmp(sortate[3].tip, "altele") != 0) {
        printf("Test sorteaza_cheltuieli (tip descrescator) a esuat\n");
        free(sortate);
        return 0;
    }
    free(sortate);

    sortate = sorteaza_cheltuieli(&cheltuieli, 1, 1);
    if (sortate[0].suma != 100 || strcmp(sortate[0].tip, "altele") != 0 ||
        sortate[1].suma != 100 || strcmp(sortate[1].tip, "mancare") != 0 ||
        sortate[2].suma != 200 || strcmp(sortate[2].tip, "altele") != 0 ||
        sortate[3].suma != 300 || strcmp(sortate[3].tip, "transport") != 0) {
        printf("Test sorteaza_cheltuieli (suma si tip crescator) a esuat\n");
        free(sortate);
        return 0;
    }
    free(sortate);
    for(int i = 0; i < cheltuieli.len;i++){
        free(cheltuieli.cheltuieli[i].tip);
    }
    free(cheltuieli.cheltuieli);
    return 1;
}

int test_all() {
    if (test_adauga_cheltuiala() == 0) {
        printf("Test adauga_cheltuiala a esuat\n");
        return 0;
    }
    
    if (test_modifica_cheltuiala() == 0) {
        printf("Test modifica_cheltuiala a esuat\n");
        return 0;
    }
    
    if (test_sterge_cheltuiala() == 0) {
        printf("Test sterge_cheltuiala a esuat\n");
        return 0;
    }
    // if (test_cauta_cheltuiala_dupa_tip() == 0) {
    //     printf("Test cauta_cheltuiala_dupa_tip a esuat\n");
    //     return 0;
    // }
    
    if (test_cauta_cheltuieli() == 0) {
        printf("Test cauta_cheltuieli a esuat\n");
        return 0;
    }
    if (test_sorteaza_cheltuieli() == 0) {
        printf("Test sorteaza_cheltuieli a esuat\n");
        return 0;
    }
    
    //###### L5
    test_filt_dupa_zi();
    test_stack();
    return 1;
}