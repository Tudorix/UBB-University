#pragma once
#include "Lista.h"
#include <string.h>
#include <assert.h>

void Add_REP(Participant p, Lista *l);
void Del_REP(int id, Lista *l);
void Mod_REP(int id, Participant p, Lista *l);
int findByID(int id, Lista *l);