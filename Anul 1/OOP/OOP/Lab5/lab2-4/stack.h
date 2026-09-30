#pragma once
#include "cheltuiala.h"

typedef struct{
    int capacitate;
    int len;
    int max_len;
    Lista **l;
}stack;

stack *initStack();
void push(Lista *l, stack *s);
void destroy(stack *s);
Lista* pop(stack *s);