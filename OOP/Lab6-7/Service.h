#pragma once
#include <iostream>
#include <cstring>
#include "Repo.h"
#include "Valid.h"
#include <bits/stdc++.h>
#include "Exception.h"
#include "Wishlist.h"
#include "Undo.h"

using namespace std;

class Service{
    private:
        Repo *repo;
        Valid valid;
        Wishlist *wish;
        int genID();
        vector<Undo*> undoList;
    public:
        Service(Repo *repo, Valid valid, Wishlist *wishlist);
        vector<Produs> getList();
        void addService(int pret, char nume[30], char tip[30], char producator[30], int id = -1);
        void modService(int id,int pret, char nume[30], char tip[30], char producator[30]);
        void delService(int id);
        int find(int id);
        float raport(int mode, char field[30]);
        vector<Produs> filter(int mode, char field[30]);
        vector<Produs> sort(int mode, int dir);

        void undo();

        void empty();
        vector<Produs> getWish();
        void addWish(int i);
        void generateWish(int nr);
        void exportWishlist(char *nume);
};