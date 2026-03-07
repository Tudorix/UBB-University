#include "Service.h"
#include "Reop.h"
#include "Valid.h"

int Add_SRV(int id, int Scor, char *Nume, char *Prenume, Lista *l){
    /**
     * Functie care adauga un Participant
     * 
     * @param id - ID Participant
     * @param Scor - Scor Participant
     * @param Nume - Nume Participant
     * @param Prenume - Prenume Participant
     * @param l - Lista cu participanti
     */
    if(validID(id) == 0) return 0;
    if(validExistaID(id,l) == 0) return 0;
    if(validScor(Scor) == 0) return 0;
    Participant p;
    p.Scor = Scor;
    p.id = id;
    strcpy(p.Nume,Nume);
    strcpy(p.Prenume,Prenume);
    Add_REP(p , l);
    return 1;
}

int Mod_SRV(int id, int scor, char *nume, char *prenume, Lista *l){
    /**
     * Functie care sterge un Participant
     * 
     * @param id - ID Participant
     * @param scor - Scor Participant
     * @param nume - Nume Participant
     * @param prenume - Prenume Participant
     * @param l - Lista cu participanti
     */
    if(validID(id) == 0) return 0;
    if(validExistaID(id,l) == 1) return 0;
    if(validScor(scor) == 0) return 0;
    Participant p;
    p.id = id;
    p.Scor = scor;
    strcpy(p.Nume,nume);
    strcpy(p.Prenume,prenume);
    Mod_REP(id, p , l);
    return 1;
}

int Del_SRV(int id, Lista *l){
    /**
     * Functie care sterge un Participant
     * 
     * @param id - id-ul participamtului
     * @param l - Lista cu participanti
     */
    if(validID(id) == 0) return 0;
    if(validExistaID(id,l) == 1) return 0;
    Del_REP(id,l);
    return 1;
}