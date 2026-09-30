//
// Created by tudorix on 20.05.2026.
//

#ifndef SIMUL_VALID_H
#define SIMUL_VALID_H
#include "Repo.h"

using namespace std;

class Valid {
    private:
        Repo &repo;
    public:
        Valid(Repo &repo) : repo(repo){}
};


#endif //SIMUL_VALID_H
