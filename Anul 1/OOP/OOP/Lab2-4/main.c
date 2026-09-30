#include "UI.h"
#include "Lista.h"
#include "Participant.h"
#include "Tets.h"

int main(){
    Lista *listaParticipanti;
    listaParticipanti = makeList();
    
    testAll(listaParticipanti);
    startConsole(listaParticipanti);
    destroy(listaParticipanti);
    return 0;
}