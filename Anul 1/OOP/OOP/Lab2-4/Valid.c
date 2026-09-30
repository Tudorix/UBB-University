#include "Valid.h"
#include "Reop.h"

int validID(int id){
    /**
     * Functie pt validare ID
     * 
     * @param id - id-ul de verificat
     * 
     * @return 1 - daca e valid, 0 - altfel
     */

    if(id <= 0) return 0;
    return 1;
}

int validScor(int scor){
    /**
     * Functie pt validare scor
     * 
     * @param scor - scorul de verificat
     * 
     * @return 1 - daca e valid, 0 - altfel
     */
    if(scor < 0 || scor > 100) return 0;
    return 1;
}

int validExistaID(int id, Lista *l){
    /**
     * Functie pt validare existenta ID
     * 
     * @param id - id-ul de verificat
     * @param l - lista de participanti
     * 
     * @return 1 - daca e valid, 0 - altfel
     */

    if(findByID(id, l) == 1) return 0;
    return 1;
}