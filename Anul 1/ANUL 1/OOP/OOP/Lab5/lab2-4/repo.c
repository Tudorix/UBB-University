#include "cheltuiala.h"
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include <stdio.h>
#include <unistd.h>
#include "stack.h"

/**
Operatiune de resize pentru lista dinamica.
*/
void resize(Lista* cheltuieli)
{
    cheltuieli->cap *= 2;
    Cheltuiala* new_cheltuieli = (Cheltuiala*) malloc(cheltuieli->cap * sizeof(Cheltuiala));
    for (int i = 0; i < cheltuieli->len; i++)
    {
        new_cheltuieli[i] = cheltuieli->cheltuieli[i];
    }
    free(cheltuieli->cheltuieli);
    cheltuieli->cheltuieli = new_cheltuieli;
}

/*
Genereaza un id unic pentru o noua cheltuiala.
*/
int gen_id(Lista* cheltuieli)
{
    int max = 0;
    for (int i = 0; i < cheltuieli->len; i++)
    {
        if (cheltuieli->cheltuieli[i].id > max)
        {
            max = cheltuieli->cheltuieli[i].id;
        }
    }
    return max + 1;
}

/*
Adauga o cheltuiala in lista de cheltuieli.
*/
void adauga_cheltuiala_repo(Lista* cheltuieli, int zi, int suma, char* tip)
{
    if (cheltuieli->len >= cheltuieli->cap)
    {
        resize(cheltuieli);
    }

    Cheltuiala c;
    c.id = gen_id(cheltuieli);
    c.zi = zi;
    c.suma = suma;
    c.tip = (char*) malloc(20);
    strcpy(c.tip, tip);

    cheltuieli->cheltuieli[cheltuieli->len] = c;
    cheltuieli->len++;
}

/*
Modifica o cheltuiala din lista de cheltuieli. Cauta cheltuiala cu id-ul dat si ii modifica ziua, suma si tipul.
*/
void modifica_cheltuiala_repo(Lista* cheltuieli, int id, int zi, int suma, char* tip)
{
    for (int i = 0; i < cheltuieli->len; i++)
    {
        if (cheltuieli->cheltuieli[i].id == id)
        {
            cheltuieli->cheltuieli[i].zi = zi;
            cheltuieli->cheltuieli[i].suma = suma;
            free(cheltuieli->cheltuieli[i].tip);
            cheltuieli->cheltuieli[i].tip = (char*) malloc(20);
            strcpy(cheltuieli->cheltuieli[i].tip, tip);
        }
    }
}

/*
Sterge o cheltuiala din lista de cheltuieli. Cauta cheltuiala cu id-ul dat si o sterge din lista.
*/
void sterge_cheltuiala_repo(Lista* cheltuieli, int id)
{
    for (int i = 0; i < cheltuieli->len; i++)
    {
        if (cheltuieli->cheltuieli[i].id == id)
        {
            free(cheltuieli->cheltuieli[i].tip);
            for (int j = i; j < cheltuieli->len - 1; j++)
            {
                cheltuieli->cheltuieli[j] = cheltuieli->cheltuieli[j + 1];
            }
            cheltuieli->len--;
        }
    }
}

void load(Lista* l, stack *s, char* filename){
    FILE * fp;
    char * line = NULL;
    size_t len = 100;
    ssize_t read;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error");
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        char *p = strtok(line, ",");
        int k = 0;
        int suma,data;
        char tip[25];
        for(int i = 1; i <= 3; i++){
            if(i == 1){
                data = atoi(p);
            }
            if(i == 2){
                suma = atoi(p);
            }
            if(i == 3){
                strcpy(tip,p);
            }
            p=strtok(NULL,",");
        }

        push(l,s);
        adauga_cheltuiala_repo(l,data,suma,tip);
    }

    fclose(fp);
    if (line)
        free(line);
}

void save(Lista* l, char* filename){
    FILE * fp;

    fp = fopen(filename, "w");
    if (fp == NULL){
        printf("Error");
        exit(1);
    }

    for(int i = 0; i < l->len;i++){
        fprintf(fp,"%d",l->cheltuieli[i].zi);
        fprintf(fp,",");
        fprintf(fp,"%d",l->cheltuieli[i].suma);
        fprintf(fp,",");
        fprintf(fp,"%s",l->cheltuieli[i].tip);
    }

    fclose(fp);
}