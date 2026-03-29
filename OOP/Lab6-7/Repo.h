#pragma once
#include <bits/stdc++.h>
#include "Produs.h"

class Repo{
    private:
        vector<Produs> lista;
    public:
        Repo(vector<Produs> lista);
        vector<Produs> getList();
        void addRepo(Produs p);
        int findById(int id);
        void delRepo(int index);
};