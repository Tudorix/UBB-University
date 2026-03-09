#include "Lista.h"
#include <stdlib.h>

Lista *makeList(){
    Lista *l = malloc(sizeof(Lista));
    l->array = malloc(10 * sizeof(Participant));
    l->capacitate = 10;
    l->len = 0;
    return l;
}

void destroy(Lista *l){
    if(l == NULL) return;
    free(l->array);
    free(l);
}


void resize(Lista *l){
    int nCap = 2 * l->capacitate;
    Participant *nParticipant = malloc(nCap * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        nParticipant[i] = l->array[i];
    }
    free(l->array);
    l->array = nParticipant;
    l->capacitate = nCap;
}

void desize(Lista *l){
    int nCap = l->capacitate / 2;
    Participant *nParticipant = malloc(nCap * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        nParticipant[i] = l->array[i];
    }
    free(l->array);
    l->array = nParticipant;
    l->capacitate = nCap;
}