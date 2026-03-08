#pragma once
#include "Lista.h"
#include "Participant.h"
#include "Reop.h"

int Add_SRV(int id, int Scor, char *Nume, char *Prenume, Lista *l);
int Del_SRV(int id, Lista *l);
int Mod_SRV(int id, int scor, char *nume, char *prenume, Lista *l);
Participant* filtrareScor(int scor, Lista *l, int *len);
Participant* filtrareLitera(char c, Lista *l, int *len);
Participant* sortareScor(int dir, Lista *l);
Participant* sortareNume(int dir, Lista *l);