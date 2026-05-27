#pragma once
#include "Repo.h"
#include "Valid.h"

using namespace std;

class Service {
    private:
        Repo repo;
        Valid valid;

    public:
        Service(Repo repo, Valid valid) : repo(std::move(repo)), valid(std::move(valid)) {};
        vector<Rochie>& get_all();
        void rent(int id);
        int find_by_name(string name);

        vector<Rochie> sort_pret();
        vector<Rochie> sort_marime();
};