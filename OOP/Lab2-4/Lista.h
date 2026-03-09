#pragma once
#include "Participant.h"


typedef struct{
    int len;
    int capacitate;
    Participant *array;
}Lista;

Lista *makeList();
void destroy(Lista *l);
void resize(Lista *l);
void desize(Lista *l);

