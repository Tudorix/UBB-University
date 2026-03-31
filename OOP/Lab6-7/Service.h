#pragma once
#include <iostream>
#include "Repo.h"
#include "Valid.h"

class Service{
    private:
        Repo *repo;
        Valid valid;
        int genID();
    public:
        Service(Repo *repo, Valid valid);
        vector<Produs> getList();
        void addService(int pret, char nume[30], char tip[30], char producator[30], int id = -1);
        void modService(int id,int pret, char nume[30], char tip[30], char producator[30]);
        void delService(int id);
        int find(int id);
        vector<Produs> filter(int mode, char field[30]);
        vector<Produs> sort(int mode, int dir);
};