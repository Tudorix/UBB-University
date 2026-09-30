#include "lista.h"
#include "stack.h"
#include "cheltuiala.h"
#include <stdlib.h>
#include <string.h>

stack *initStack(){
    stack *s = (stack*)malloc(sizeof(stack)); 
    s->capacitate = 100;
    s->len = 0;
    s->max_len = 0;
    s->l = (Lista**)malloc(s->capacitate * sizeof(Lista*));
    return s;
}

void push(Lista *l, stack *s){
    if(s->len < s->capacitate){
        s->l[s->len] = (Lista*)malloc(sizeof(Lista));
        s->l[s->len]->cap = l->cap;
        s->l[s->len]->len = l->len;
        s->l[s->len]->cheltuieli = malloc(l->cap * sizeof(Cheltuiala));
        for(int i = 0; i < l->len; i++){
            s->l[s->len]->cheltuieli[i].id = l->cheltuieli[i].id;
            s->l[s->len]->cheltuieli[i].suma = l->cheltuieli[i].suma;
            s->l[s->len]->cheltuieli[i].zi = l->cheltuieli[i].zi;
            s->l[s->len]->cheltuieli[i].tip = (char*) malloc(20);
            strcpy(s->l[s->len]->cheltuieli[i].tip ,l->cheltuieli[i].tip);
        }
        s->len++;
        s->max_len++;
    }
}

Lista* pop(stack *s){
    if(s->len == 0)
        return s->l[0];
    
    s->len--;
    return s->l[s->len];
}

void destroy(stack *s){
    for(int i = 0; i < s->max_len;i++){
        for(int j = 0; j < s->l[i]->len;j++){
            free(s->l[i]->cheltuieli[j].tip);
        }
        free(s->l[i]->cheltuieli);
        free(s->l[i]);
    }
    free(s->l);
    free(s);
}