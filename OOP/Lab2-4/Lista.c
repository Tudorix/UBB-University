#include "Lista.h"
#include <stdlib.h>

Lista *makeList(){
    /**
     * Constructor pentru lista
     */
    Lista *l = malloc(sizeof(Lista));
    l->array = malloc(10 * sizeof(Participant));
    l->capacitate = 10;
    l->len = 0;
    return l;
}

void destroy(Lista *l){
    /**
     * Destructor pentru lista
     * 
     * @param l - lista de Participanti
     */
    if(l == NULL) return;
    free(l->array);
    free(l);
}

void resize(Lista *l){
    /**
     * Functie care mareste spatiul de stocare a listei
     * 
     * @param l - lista de Participanti
     */
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
    /**
     * Functie care scade spatiul de stocare a listei
     * 
     * @param l - lista de Participanti
     */
    int nCap = l->capacitate / 2;
    Participant *nParticipant = malloc(nCap * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        nParticipant[i] = l->array[i];
    }
    free(l->array);
    l->array = nParticipant;
    l->capacitate = nCap;
}