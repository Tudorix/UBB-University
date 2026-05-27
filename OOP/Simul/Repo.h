//
// Created by tudorix on 20.05.2026.
//

#ifndef SIMUL_REPO_H
#define SIMUL_REPO_H
#include <string>
#include <vector>
#include "Produs.h"

using namespace std;

class Repo
{
private:
    vector<Produs> lista;
    string fn;

public:
    // Constructor Repo
    Repo(string fn);

    // Functie care citeste din fisier
    void readFromFile();

    // Functie care returneaza lista de porduse
    vector<Produs>& getAll();
};


#endif //SIMUL_REPO_H
