#include "UI.h"
#include "Lista.h"
#include "Participant.h"
#include "Tets.h"

int main(){
    Lista listaParticipanti;
    listaParticipanti.len = 0;
    
    testAll(&listaParticipanti);
    startConsole(&listaParticipanti);
    return 0;
}