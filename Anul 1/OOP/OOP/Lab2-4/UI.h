#pragma once
#include <stdio.h>
#include <string.h>
#include "Participant.h"
#include "Lista.h"
#include "Reop.h"
#include "Service.h"

void startConsole(Lista *l);
void showCommands();
void printParticipants(Lista *l);
void readParticiant(int *id,int *scor, char *nume, char *prenume, char *pref);