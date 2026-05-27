#pragma once
#include <string>
#include <vector>

#include "Rochie.h"

using namespace std;

class Repo {

    private:
        string fn;
        vector<Rochie> rochie;

    public:
        Repo(string const &filename);
        void add(Rochie const &rochie);

        int get_by_name(string const &name);

        void rd();
        void wr();
        vector<Rochie>& get_all();
};