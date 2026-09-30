//
// Created by tudorix on 17.05.2026.
//

#ifndef SUBSIM_VALID_H
#define SUBSIM_VALID_H
#include "Repo.h"

class Valid {
    private:
    Repo repo;

    public:
    Valid(Repo repo) : repo(std::move(repo)) {}

};


#endif //SUBSIM_VALID_H
