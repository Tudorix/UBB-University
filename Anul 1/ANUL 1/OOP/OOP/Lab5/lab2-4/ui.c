#include "ui.h"
#include "lista.h"
#include "service.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void printStack(stack *s){
    for(int i = 0; i < s->len; i++){
        for(int j = 0; j < s->l[i]->len; j++){
            printf("%d ", s->l[i]->cheltuieli[j].id);
        }
        printf("\n");
    }
}

int meniu(Lista* cheltuieli, stack* s) {

    while (1) {
        printf("Gestiunea bugetului\n\n");
        printf("1) Adauga cheltuiala\n");
        printf("2) Modifica cheltuiala\n");
        printf("3) Sterge cheltuiala\n");
        printf("4) Cauta cheltuiala\n");
        printf("5) Filtreaza cheltuieli\n");
        printf("6) Afiseaza toate cheltuielile ordonate\n");
        printf("7) Filtrare dupa zi\n");
        printf("8) Undo\n");
        printf("E) Iesire\n");
        printf("\nOptiunea: ");
        
        char opt;
        scanf(" %c", &opt);
        
        if (opt == 'E' || opt == 'e') {
            break;
        } else if (opt == '1') {
            int zi, suma;
            char tip[20];
            printf("zi: ");
            scanf("%d", &zi);
            printf("suma: ");
            scanf("%d", &suma);
            printf("tip: ");
            scanf("%s", tip);

            push(cheltuieli,s);
            int res = adauga_cheltuiala(cheltuieli, zi, suma, tip);
            if (res == 0) {
                printf("A aparut o eroare la adaugare\n\n");
            }
            printStack(s);
        } else if (opt == '2') {
            int id, zi, suma;
            char tip[20];
            printf("id: ");
            scanf("%d", &id);
            printf("zi: ");
            scanf("%d", &zi);
            printf("suma: ");
            scanf("%d", &suma);
            printf("tip: ");
            scanf("%s", tip);
            
            push(cheltuieli,s);
            int res = modifica_cheltuiala(cheltuieli, id, zi, suma, tip);
            if (res == 0) {
                printf("A aparut o eroare la modificare\n\n");
            } else if (res == -1) {
                printf("Nu exista o cheltuiala cu id-ul dat\n\n");
            }
        } else if (opt == '3') {
            int id;
            printf("id: ");
            scanf("%d", &id);
            
            push(cheltuieli,s);
            int res = sterge_cheltuiala(cheltuieli, id);
            if (res == 0) {
                printf("A aparut o eroare la stergere\n\n");
            } else if (res == -1) {
                printf("Nu exista o cheltuiala cu id-ul dat\n\n");
            }
        } else if (opt == '4') {
            char tip[20];
            printf("tip: ");
            scanf("%s", tip);

            Lista* lista_noua = cauta_cheltuiala_dupa_tip(cheltuieli, tip);
            printf("lista veche: ");
            for (int i = 0; i < cheltuieli->len; i++) {
                printf("%d ", cheltuieli->cheltuieli[i].id);
            }
            printf("\n");
            printf("lista noua: ");
            for (int i = 0; i < lista_noua->len; i++) {
                printf("%d ", lista_noua->cheltuieli[i].id);
            }
            printf("\n\n");
            free(lista_noua->cheltuieli);
            free(lista_noua);
        } else if (opt == '5') {
            int zi, suma;
            char* tip = malloc(20 * sizeof(char));
            
            printf("Dati ziua dupa care sa se filtreze (sau 0 pentru a se ignora): ");
            scanf("%d", &zi);

            printf("Dati suma dupa care sa se filtreze (sau 0 pentru a se ignora): ");
            scanf("%d", &suma);

            printf("Dati tipul dupa care sa se filtreze (sau - pentru a se ignora): ");
            scanf("%s", tip);

            struct OptiuniCautaCheltuieli optiuni;
            optiuni.zi = zi;
            optiuni.suma = suma;
            optiuni.tip = strcmp(tip, "-") == 0 ? "" : tip;
            optiuni.cheltuieli = malloc(cheltuieli->len * sizeof(Cheltuiala));
            optiuni.nr_cheltuieli = 0;
            
            cauta_cheltuieli(cheltuieli, &optiuni);

            if (optiuni.nr_cheltuieli == 0) {
                printf("Nu exista cheltuieli\n\n");
            }

            for (int i = 0; i < optiuni.nr_cheltuieli; i++) {
                printf("%d. Zi: %d Suma: %d Tip: %s\n", optiuni.cheltuieli[i].id, optiuni.cheltuieli[i].zi, optiuni.cheltuieli[i].suma, optiuni.cheltuieli[i].tip);
            }
            free(optiuni.cheltuieli);
            free(tip);
        } else if (opt == '6') {
            int dir_suma, dir_tip;
            printf("Directia de sortare dupa suma (0 = ignorare, 1 = crescator, -1 = descrescator): \n");
            scanf("%d", &dir_suma);
            printf("Directia de sortare dupa tip (0 = ignorare, 1 = crescator, -1 = descrescator): \n");
            scanf("%d", &dir_tip);

            if (cheltuieli->len == 0) {
                printf("Nu exista cheltuieli\n\n");
            } else {
                Cheltuiala* sortate = sorteaza_cheltuieli(cheltuieli, dir_suma, dir_tip);
                for (int i = 0; i < cheltuieli->len; i++) {
                    printf("%d. Zi: %d Suma: %d Tip: %s\n", sortate[i].id, sortate[i].zi, sortate[i].suma, sortate[i].tip);
                }
                printf("\n");
                free(sortate);
            }
        }
        else if (opt == '7') {
            int len;
            if (cheltuieli->len == 0) {
                printf("Nu exista cheltuieli\n\n");
            } else {
                int zi;
                printf("Dupa ce zi sa filtram: ");
                scanf("%d", &zi);
                Cheltuiala* sortate = filtarare_dupa_zi(cheltuieli, zi, &len);
                for (int i = 0; i < len; i++) {
                    printf("%d. Zi: %d Suma: %d Tip: %s\n", sortate[i].id, sortate[i].zi, sortate[i].suma, sortate[i].tip);
                }
                printf("\n");
                free(sortate);
                if(len == 0){
                    printf("Nu exista nicion cheltuiala in acea zi\n");
                }
            }
        }
        else if (opt == '8') {
            if(s->len > 0){
                cheltuieli = pop(s);
                for(int i = 0; i < cheltuieli->len;i++){
                    printf("%d ",cheltuieli->cheltuieli[i].id);
                }
                printf("\n");
            }else{
                printf("There is nothing to undo\n");
            }
        }
        else if (opt == '9') {
            if(cheltuieli->len > 0){

                for(int i = 0; i < cheltuieli->len;i++){
                    printf("%d %d %d %s",cheltuieli->cheltuieli[i].id, cheltuieli->cheltuieli[i].zi, cheltuieli->cheltuieli[i].suma, cheltuieli->cheltuieli[i].tip);
                }
                printf("\n");
            }else{
                printf("There is nothing to print\n");
            }
        } else {
            printf("Optiune invalida\n");
        } 
    }

    return 0;
}