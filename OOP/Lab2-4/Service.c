#include "Service.h"
#include "Reop.h"
#include "Valid.h"
#include <stdlib.h>

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

Participant* filtrareScor(int scor, Lista *l, int *len){
    /**
     * Functie care filtreaza Participanti dupa scor
     * 
     * @param scor - scorul dupa care se filtreaza
     * @param l - lista cu participanti
     * 
     * @return un pointer catre lista filtrata
     */
    int lenght = 0;
    Participant *out = malloc((l->len) * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        if(l->array[i].Scor < scor){
            out[lenght++] = l->array[i];
        }
    }
    *len = lenght;
    return out;
}

Participant* filtrareLitera(char c, Lista *l, int *len){
    /**
     * Functie care filtreaza Participanti dupa litera
     * 
     * @param scor - scorul dupa care se filtreaza
     * @param l - lista cu participanti
     * 
     * @return un pointer catre lista filtrata
     */
    int lenght = 0;
    Participant *out = malloc((l->len) * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        if(l->array[i].Prenume[0] == c){
            out[lenght++] = l->array[i];
        }
    }
    *len = lenght;
    return out;
}

Participant* sortareScor(int dir, Lista *l){
    /**
     * Functie care sorteaza Participanti dupa scor
     * 
     * @param l - lista cu participanti
     * @param dir - directia de sortare(crescator = 0 sau descrescator = altfel)
     */
    Participant aux;
    Participant *out = malloc((l->len) * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        out[i] = l->array[i];
    }

    if(dir == 0){
        int check = 0;
        do{
            check = 1;
            for(int i = 0; i < l->len - 1;i++){
                if(out[i].Scor > out[i + 1].Scor){
                    aux = out[i];
                    out[i] = out[i + 1];
                    out[i + 1] = aux;
                    check = 0;
                }
            }
        }while(check == 0);
    }else{
        int check = 0;
        do{
            check = 1;
            for(int i = 0; i < l->len - 1;i++){
                if(out[i].Scor < out[i + 1].Scor){
                    aux = out[i];
                    out[i] = out[i + 1];
                    out[i + 1] = aux;
                    check = 0;
                }
            }
        }while(check == 0);
    }
    return out;
}

int checkName(char *c, char *g){
    /**
     * Functie care verifica daca un c este egal cu g sau daca c este subsir al lui g
     * 
     * @param c - sirul de verificat
     * @param l - sirul de baza
     * 
     * @return - 1 daca este egal sau subsir, 0 altfel
     */

    char cc[strlen(c)];
    char cg[strlen(g)];
    strcpy(cc,c);
    strcpy(cg,g);

    for(int i = 0; i < strlen(c); i++){
        if(cc[i] >= 'a' && cc[i] <= 'z'){
            cc[i] -= 'a' - 'A';
        }
    }

    for(int i = 0; i < strlen(g); i++){
        if(cg[i] >= 'a' && cg[i] <= 'z'){
            cg[i] -= 'a' - 'A';
        }
    }

    if(strcmp(cg,cc) == 0) return 1;
    if(strstr(cg,cc) != NULL) return 1;
    return 0;
}

Participant* findByName(char *c, Lista *l, int *len){
    /**
     * Functie care gaseste un Participant dupa nume
     * 
     * @param c - numele pe care il cautam
     * @param l - lista de participanti
     * @param len - lungimea sirului de iesire
     * 
     * @return - pointer spre lista de cautati
     */
    int lenght = 0;
    Participant *out = malloc((l->len) * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        if(checkName(c,l->array[i].Nume) == 1 || checkName(c,l->array[i].Prenume) == 1){
            out[lenght++] = l->array[i];
        }
    }
    *len = lenght;
    return out;
}

Participant* sortareNume(int dir, Lista *l){
    /**
     * Functie care sorteaza Participanti dupa scor
     * 
     * @param l - lista cu participanti
     * @param dir - directia de sortare(crescator = 0 sau descrescator = altfel)
     * 
     * @return - pointer spre lista sortata
     */
    Participant aux;
    Participant *out = malloc((l->len) * sizeof(Participant));
    for(int i = 0; i < l->len; i++){
        out[i] = l->array[i];
    }

    if(dir == 0){
        int check = 0;
        do{
            check = 1;
            for(int i = 0; i < l->len - 1;i++){
                if(strcmp(out[i].Nume,out[i + 1].Nume) > 0){
                    aux = out[i];
                    out[i] = out[i + 1];
                    out[i + 1] = aux;
                    check = 0;
                }else if(strcmp(out[i].Nume,out[i + 1].Nume) == 0){
                    if(strcmp(out[i].Prenume,out[i + 1].Prenume) > 0){
                        aux = out[i];
                        out[i] = out[i + 1];
                        out[i + 1] = aux;
                        check = 0;
                    }
                }
            }
        }while(check == 0);
    }else{
        int check = 0;
        do{
            check = 1;
            for(int i = 0; i < l->len - 1;i++){
                if(strcmp(out[i].Nume,out[i + 1].Nume) < 0){
                    aux = out[i];
                    out[i] = out[i + 1];
                    out[i + 1] = aux;
                    check = 0;
                }else if(strcmp(out[i].Nume,out[i + 1].Nume) == 0){
                    if(strcmp(out[i].Prenume,out[i + 1].Prenume) < 0){
                        aux = out[i];
                        out[i] = out[i + 1];
                        out[i + 1] = aux;
                        check = 0;
                    }
                }
            }
        }while(check == 0);
    }
    return out;
}