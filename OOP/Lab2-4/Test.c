#include "Tets.h"
#include <stdio.h>

void testAdd(Lista *l){
    /**
     * Functie care testeaza Adaugarea
     */
    Add_SRV(1,56, "Maria", "Andrei", l);
    Add_SRV(2,87, "Ionescu", "Tudor", l);
    Add_SRV(3, 95, "Mircea", "Antonia", l);
    Add_SRV(4, 95, "Jors", "Casian", l);
    Add_SRV(5, 100, "Popescu", "Marius", l);
    Add_SRV(6, 70, "Bostan", "Carol", l);
    Add_SRV(7, 85, "Kutasi", "Arpad", l);
    Add_SRV(7, 95, "Valicu", "Aurel", l);
    assert(strcmp(l->array[0].Nume,"Maria") == 0);
    assert(strcmp(l->array[1].Prenume,"Tudor") == 0);
    assert(l->array[2].Scor == 95);
    assert(strcmp(l->array[3].Nume,"Jors") == 0);
    assert(l->len == 7);
}

void testDel(Lista *l){
    /**
     * Functie care testeaza Stergere
     */
    Del_SRV(1,l);
    assert(strcmp(l->array[0].Nume,"Ionescu") == 0);
    assert(strcmp(l->array[0].Prenume,"Tudor") == 0);
    assert(l->len == 6);
    Del_SRV(2,l);
    assert(strcmp(l->array[0].Nume,"Mircea") == 0);
    assert(strcmp(l->array[0].Prenume,"Antonia") == 0);
    assert(l->len == 5);
}

void testMod(Lista *l){
    /**
     * Functie care testeaza Modificarea
     */
    assert(strcmp(l->array[0].Nume,"Mircea") == 0);
    assert(strcmp(l->array[0].Prenume,"Antonia") == 0);
    assert(l->array[0].Scor == 95);
    assert(l->len == 5);
    Mod_SRV(3,98,"Ardelean", "Gabriel",l);
    assert(strcmp(l->array[0].Nume,"Ardelean") == 0);
    assert(strcmp(l->array[0].Prenume,"Gabriel") == 0);
    assert(l->array[0].Scor == 98);
    assert(l->len == 5);
}

void testFilt(Lista *l){
    /**
     * Functie care testeaza Filtrare dupa Scor si prima litera
     */
    Participant *p;
    int len;

    p = filtrareScor(56, l, &len);
    assert(len == 0);
    p = filtrareScor(90, l, &len);
    assert(len == 2);
    assert(p[0].id == 6);
    assert(p[0].Scor == 70);

    p = filtrareLitera('X',l,&len);
    assert(len == 0);
    p = filtrareLitera('A',l,&len);
    assert(len == 1);
    assert(p[0].id == 7);
    assert(p[0].Scor == 85);
}

void testSortScor(Lista *l){
    /**
     * Functie care testeaza sortarea dupa Scor
     */
    Participant *p;
    p = sortareScor(0,l);
    assert(p[0].id == 6);
    assert(p[0].Scor == 70);
    assert(strcmp(p[0].Nume, "Bostan") == 0);
    assert(strcmp(p[0].Prenume, "Carol") == 0);
    p = sortareScor(1,l);
    assert(p[0].id == 5);
    assert(p[0].Scor == 100);
    assert(strcmp(p[0].Nume, "Popescu") == 0);
    assert(strcmp(p[0].Prenume, "Marius") == 0);
}

void testSortNume(Lista *l){
    /**
     * Functie care testeaza sortarea dupa Scor
     */
    Participant *p;
    p = sortareNume(0,l);
    assert(p[0].id == 3);
    assert(p[0].Scor == 98);
    assert(strcmp(p[0].Nume, "Ardelean") == 0);
    assert(strcmp(p[0].Prenume, "Gabriel") == 0);
    p = sortareNume(1,l);
    assert(p[0].id == 5);
    assert(p[0].Scor == 100);
    assert(strcmp(p[0].Nume, "Popescu") == 0);
    assert(strcmp(p[0].Prenume, "Marius") == 0);
}

void testAll(Lista *l){
    /**
     * Functie care apeleaza toate testele
     */
    testAdd(l);
    testDel(l);
    testMod(l);
    testFilt(l);
    testSortScor(l);
    testSortNume(l);
}