#pragma once
#include <vector>
#include <fstream>
#include "Produs.h"

using namespace std;

class Wishlist{
    private:
        vector<Produs> lista;
    public:
        Wishlist(vector<Produs> lista);
        void empty();
        void add(Produs p);
        vector<Produs> getList();
        void Export(string fn);
};