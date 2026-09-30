#include "Reop.h"

void Add_REP(Participant p, Lista *l){
    /**
     * Functie care adauga un Participant
     * 
     * @param p - Participantul de adaugat
     * @param l - Lista cu participanti
     */
    if(l->len == l->capacitate){
        resize(l);
    }
    l->array[l->len].Scor = p.Scor; 
    l->array[l->len].id = p.id; 
    strcpy(l->array[l->len].Nume, p.Nume);
    strcpy(l->array[l->len].Prenume, p.Prenume);
    l->len += 1;
}

void Del_REP(int id, Lista *l){
    /**
     * Functie care sterge un Participant
     * 
     * @param id - id-ul participamtului
     * @param l - Lista cu participanti
     */
    int i = 0;
    while(id != l->array[i].id) i++;

    for(int j = i; j < l->len - 1; j++){
        l->array[j].id = l->array[j + 1].id;
        l->array[j].Scor = l->array[j + 1].Scor;
        strcpy(l->array[j].Nume,l->array[j + 1].Nume);
        strcpy(l->array[j].Prenume,l->array[j + 1].Prenume);
    }
    l->len--;

    if(l->len == l->capacitate / 2 && l->capacitate > 10){
        desize(l);
    }
}

void Mod_REP(int id, Participant p, Lista *l){
    /**
     * Functie care sterge un Participant
     * 
     * @param id - id-ul participamtului
     * @param p - Participantul modificat
     * @param l - Lista cu participanti
     */
    int i = 0;
    while(id != l->array[i].id) i++;

    l->array[i].id = p.id;
    l->array[i].Scor = p.Scor;
    strcpy(l->array[i].Nume,p.Nume);
    strcpy(l->array[i].Prenume,p.Prenume);
}

int findByID(int id, Lista *l){
    /**
     * Functie care verifica daca exista un anumit ID in lista
     * 
     * @param id(int) - id-ul cautat
     * @param l(Lista) - lista de participanti
     * 
     * @return 1 - daca exista in lista, 0 - altfel
     */
    for(int i = 0; i < l->len; i++){
        if(l->array[i].id == id){
            return 1;
        }
    }
    return 0;
}