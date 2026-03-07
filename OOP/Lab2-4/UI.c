#include "UI.h"
#include <string.h>

void showCommands(){
    printf("1 - Print Participants\n");
    printf("2 - Add Participants\n");
    printf("3 - Delete Participants\n");
    printf("4 - Modify Participants\n");
    printf("0 - Exit\n");
}

void printParticipants(Lista *l){
    printf("-----\n");
    for(int i = 0; i < l->len; i++){
        printf("%d - %s %s: %d\n",l->array[i].id , l->array[i].Nume , l->array[i].Prenume, l->array[i].Scor);
    }
    if(l -> len == 0){
        printf("The list is empty\n");
    }
    printf("-----\n");
}

void readParticiant(int *id,int *scor, char *nume, char *prenume, char *pref){
    int verif = 0;
    //Get ID
    while(verif == 0){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        printf("Enter the ID\n>>>");
        verif = scanf("%d", id);
    }
    verif = 0;
    //Get scor
    while(verif == 0){
        int c;
        while((c = getchar()) != '\n' && c != EOF);
        printf("Enter the %s Score\n>>>",pref);
        verif = scanf("%d", scor);
    }
    getchar();
    //Get Prenume
    printf("Enter the %s First Name\n>>>", pref);
    fgets(prenume, 30, stdin);
    //Get Nume
    printf("Enter the %s Last Name\n>>>", pref);
    fgets(nume, 30, stdin);
}

void startConsole(Lista *l){
    int running = 1;
    while(running){
        showCommands();
        printf("Enter a command:\n>>> ");
        int com;
        int rez = scanf("%d", &com);
        if(rez > 0){
            if(com == 0){
                running = 0;
            }else if(com == 1){
                printParticipants(l);
            }else if(com == 2){
                int id, scor;
                char nume[30], prenume[30];
                char pref[5] = "";
                readParticiant(&id, &scor, nume, prenume, pref);
                nume[strlen(nume) - 1] = '\0';
                prenume[strlen(prenume) - 1] = '\0';
                int rez = Add_SRV(id, scor, nume, prenume, l); 
                if(rez == 1) printf("<<< Participand added >>>\n");
                else printf("<<< Failed to add Participant(incorrect data) >>> \n");
            }
            else if(com == 3){
                int id = 0;
                while(id == 0){
                    int c;
                    while((c = getchar()) != '\n' && c != EOF);
                    printf("Enter a id\n>>>");
                    scanf("%d", &id);
                }
                int rez = Del_SRV(id,l);
                if(rez == 1) printf("<<< Participand deleted >>>\n");
                else printf("<<< Failed to delete Participant(incorrect data) >>> \n");
            }
            else if(com == 4){
                int id, scor;
                char nume[30], prenume[30];
                char pref[5] = "NEW";
                readParticiant(&id, &scor, nume, prenume, pref);
                nume[strlen(nume) - 1] = '\0';
                prenume[strlen(prenume) - 1] = '\0';
                int rez = Mod_SRV(id, scor, nume, prenume, l); 
                if(rez == 1) printf("<<< Participand modified >>>\n");
                else printf("<<< Failed to modify Participant(incorrect data) >>>\n");
            }
            else{
                printf("Enter a valid command\n");
            }
        }else{
            int c;
            while((c = getchar()) != '\n' && c != EOF);
        }
    }
    printf("Rock on!");
}