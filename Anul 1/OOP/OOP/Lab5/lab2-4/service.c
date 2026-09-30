#include "service.h"
#include "cheltuiala.h"
#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
Adauga o cheltuiala in lista de cheltuieli. Returneaza 1 daca adaugarea a fost realizata cu succes, 0 altfel.
*/
int adauga_cheltuiala(Lista* cheltuieli, int zi, int suma, char* tip)
{
    if (zi < 1 || zi > 31) return 0;
    if (suma < 0) return 0;
    if (strcmp(tip, "mancare") != 0 && strcmp(tip, "transport") != 0 && strcmp(tip, "telefon&internet") != 0 && strcmp(tip, "inbracaminte") != 0 && strcmp(tip, "altele") != 0) return 0;

    adauga_cheltuiala_repo(cheltuieli, zi, suma, tip);
    return 1;
}

Cheltuiala* filtarare_dupa_zi(Lista *l, int zi, int *len){
    /**
     * Functie care filtreaza lista de cheltuieli dupa zi
     */
    if (zi < 1 || zi > 31) return 0;
    Cheltuiala *c = malloc(l->len * sizeof(Cheltuiala));
    int length = 0;
    for(int i = 0 ; i < l->len; i++){
        if(l->cheltuieli[i].zi == zi){
            c[length++] = l->cheltuieli[i];
        }
    }
    *len = length;
    return c;
}

/*
Modifica o cheltuiala din lista de cheltuieli. Returneaza 1 daca modificarea a fost realizata cu succes, -1 daca nu exista o cheltuiala cu id-ul dat, 0 altfel.
*/
int modifica_cheltuiala(Lista* cheltuieli, int id, int zi, int suma, char* tip)
{
    if (id < 0) return 0;
    if (zi < 1 || zi > 31) return 0;
    if (suma < 0) return 0;
    if (strcmp(tip, "mancare") != 0 && strcmp(tip, "transport") != 0 && strcmp(tip, "telefon&internet") != 0 && strcmp(tip, "inbracaminte") != 0 && strcmp(tip, "altele") != 0) return 0;

    for (int i = 0; i < cheltuieli->len; i++)
    {
        if (cheltuieli->cheltuieli[i].id == id)
        {
            modifica_cheltuiala_repo(cheltuieli, id, zi, suma, tip);
            return 1;
        }
    }
    return -1;
}

/*
Sterge o cheltuiala din lista de cheltuieli. Returneaza 1 daca stergerea a fost realizata cu succes, -1 daca nu exista o cheltuiala cu id-ul dat, 0 altfel.
*/
int sterge_cheltuiala(Lista* cheltuieli, int id)
{
    if (id < 0) return 0;

    for (int i = 0; i < cheltuieli->len; i++)
    {
        if (cheltuieli->cheltuieli[i].id == id)
        {
            sterge_cheltuiala_repo(cheltuieli, id);
            return 1;
        }
    }
    return -1;
}

// functie care cauta cheltuiala dupa tip. Verificica de asemenea daca tipul este inclus. Returneaza id daca exista o cheltuiala cu tipul dat, 0 daca nu.
Lista* cauta_cheltuiala_dupa_tip(Lista* cheltuieli, char *tip) {
    Lista* lista_noua = malloc(sizeof(Lista));
    lista_noua->cheltuieli = malloc(cheltuieli->len * sizeof(Cheltuiala));
    lista_noua->len = cheltuieli->len;
    lista_noua->cap = cheltuieli->len;
    
    int fr_chelt[100] = {0}; // elem gasit
    for (int i = 0; i < cheltuieli->len; i++) {
        if (strstr(cheltuieli->cheltuieli[i].tip, tip) != NULL) {
            fr_chelt[i] = 1;
        }
    }

    int fr_puse[100] = {0}; // elem puse
    for (int i = 0; i < cheltuieli->len; i++) {
        if (fr_chelt[i] == 1) {
            int poz;
            do {
                poz = rand() % cheltuieli->len;
            } while (fr_puse[poz] == 1);
            printf("poz: %d\n", poz);
            fr_puse[poz] = 1;

            lista_noua->cheltuieli[poz] = cheltuieli->cheltuieli[i];
        }
    }

    int k = 0;
    for (int i = 0; i < cheltuieli->len; i++) {
        while (fr_puse[k] == 1) {
            k++;
        }
        
        if (fr_chelt[i] == 0) {
            fr_puse[k] = 1;
            lista_noua->cheltuieli[k] = cheltuieli->cheltuieli[i];
            k++;
        }
    }

    return lista_noua;
}

// functie care cauta cheltuiala dupa parametrii. Daca un parametru e 0 sau "" atunci e ignorat.
void cauta_cheltuieli(Lista* cheltuieli, struct OptiuniCautaCheltuieli* optiuni) {
    for (int i = 0; i < cheltuieli->len; i++) {
        Cheltuiala cheltuiala = cheltuieli->cheltuieli[i];

        if (optiuni->suma > 0 && optiuni->suma != cheltuiala.suma) continue;
        if (optiuni->zi > 0 && optiuni->zi != cheltuiala.zi) continue;
        if (strlen(optiuni->tip) > 0 && strcmp(optiuni->tip, cheltuiala.tip)) continue;

        optiuni->cheltuieli[optiuni->nr_cheltuieli] = cheltuiala;
        optiuni->nr_cheltuieli++;
    }
}

/**
* Functie care compara 2 cheltuieli pentru a determina care e mai mica / mai mare
*/
int cmp_cheltuieli(Cheltuiala a, Cheltuiala b, int dir_suma, int dir_tip) {
    if (dir_suma != 0 && a.suma != b.suma) {
        if (dir_suma > 0) {
            return a.suma > b.suma;
        } else {
            return a.suma < b.suma;
        }
    }

    if (dir_tip != 0 && strcmp(a.tip, b.tip) != 0) {
        int cmp_str = strcmp(a.tip, b.tip);
        if (dir_tip > 0) {
            return cmp_str > 0;
        } else {
            return cmp_str < 0;
        }
    }

    return 0;
}

/**
*   functie care returneaza un nou vector de cheltuieli sortate crescator/descrescator in functie de suma/tip. 
*   @param cheltuieli vectorul cu cheltuieli
*   @param nr_cheltuieli numarul de cheltuieli
*   @param dir_suma directia de sortare dupa suma (0 pentru a nu sorta dupa suma, >0 pentru crescator, <0 pentru descrescator)
*   @param dir_tip directia de sortare dupa tip (0 pentru a nu sorta dupa tip, >0 pentru crescator, <0 pentru descrescator)
*/
Cheltuiala* sorteaza_cheltuieli(Lista* cheltuieli, int dir_suma, int dir_tip) {
    Cheltuiala* cheltuieli_sortate = malloc(cheltuieli->len * sizeof(Cheltuiala));
    
    for (int i = 0; i < cheltuieli->len; i++) {
        cheltuieli_sortate[i] = cheltuieli->cheltuieli[i];
    }

    for (int i = 0; i < cheltuieli->len - 1; i++) {
        for (int j = i + 1; j < cheltuieli->len; j++) {
            if (cmp_cheltuieli(cheltuieli_sortate[i], cheltuieli_sortate[j], dir_suma, dir_tip) == 1) {
                Cheltuiala aux = cheltuieli_sortate[i];
                cheltuieli_sortate[i] = cheltuieli_sortate[j];
                cheltuieli_sortate[j] = aux;
            }
        }
    }

    return cheltuieli_sortate;
}