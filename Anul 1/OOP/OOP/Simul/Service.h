//
// Created by tudorix on 20.05.2026.
//

#ifndef SIMUL_SERVICE_H
#define SIMUL_SERVICE_H
#include "Repo.h"
#include "Valid.h"

using namespace std;

class Service {
    private:
        Repo &repo;
        Valid &valid;
    public:
        // Constructor Service
        Service(Repo &repo, Valid &valid) : repo{repo} , valid{valid} {}

    // Functie care returneaza lista de porduse
    vector<Produs>& getAll();
};


#endif //SIMUL_SERVICE_H
