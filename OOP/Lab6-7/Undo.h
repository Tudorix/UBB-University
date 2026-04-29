#pragma once
#include <vector>
#include "Repo.h"
#include "Produs.h"
#include "Wishlist.h"

using namespace std;

class Undo{
    public:
        virtual ~Undo() = default;
        virtual void undo() = 0;
};

class UndoAdd : public Undo{
    private:
        Repo *repo;
        Produs p;
    public:
        UndoAdd(Repo *repo, Produs p){
            this->repo = repo;
            this->p = p;
        }
        void undo() override{
            this->repo->delRepo(this->repo->findById(p.getID()));
        };
};

class UndoDel : public Undo{
    private:
        Repo *repo;
        Produs p;
    public:
        UndoDel(Repo *repo, Produs p){
            this->repo = repo;
            this->p = p;
        }
        void undo() override{
            this->repo->addRepo(p);
        };
};

class UndoMod : public Undo{
    private:
        Repo *repo;
        Produs p;
        Produs q;
    public:
        UndoMod(Repo *repo, Produs p, Produs q){
            this->repo = repo;
            this->p = p;
            this->q = q;
        }
        
        void undo() override{
            int index = this->repo->findById(p.getID());
            p.afiseaza();
            this->repo->delRepo(index);
            q.afiseaza();
            this->repo->addRepo(q);
        };
};