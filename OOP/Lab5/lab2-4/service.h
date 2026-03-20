#pragma once
#include "repo.h"

int adauga_cheltuiala(Lista* cheltuieli, int zi, int suma, char* tip);
int sterge_cheltuiala(Lista* cheltuieli, int id);
int modifica_cheltuiala(Lista* cheltuieli, int id, int zi, int suma, char* tip);
Lista* cauta_cheltuiala_dupa_tip(Lista* cheltuieli, char *tip);

struct OptiuniCautaCheltuieli {
    int zi;
    int suma;
    char *tip;
    Cheltuiala *cheltuieli;
    int nr_cheltuieli;
};
void cauta_cheltuieli(Lista* cheltuieli, struct OptiuniCautaCheltuieli* optiuni);
Cheltuiala* sorteaza_cheltuieli(Lista* cheltuieli, int dir_suma, int dir_tip);
Cheltuiala* filtarare_dupa_zi(Lista *l, int zi, int *len);