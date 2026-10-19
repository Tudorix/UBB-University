#pragma once
#include <iostream>
#include "Produs.h"
#include <bits/stdc++.h>

using namespace std;

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