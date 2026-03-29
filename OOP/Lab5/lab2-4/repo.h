#pragma once
#include "cheltuiala.h"
#include "lista.h"
#include <string.h>
#include "stack.h"

void adauga_cheltuiala_repo(Lista* cheltuieli, int zi, int suma, char* tip);
void sterge_cheltuiala_repo(Lista* cheltuieli, int id);
void modifica_cheltuiala_repo(Lista* cheltuieli, int id, int zi, int suma, char* tip);
void resize(Lista* cheltuieli);
void load(Lista* l,stack *s, char* filename);
void save(Lista* l, char* filename);