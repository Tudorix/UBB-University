#include "Matrice.h"
#include <exception>
#include <iostream>

#define INF 999999;

using namespace std;

// Theta(1)
Matrice::Nod::Nod(int l, int c, TElem v) {
    linie = l;
    coloana = c;
    valoare = v;
    st = nullptr;
    dr = nullptr;
}

// Theta(1)
Matrice::Matrice(int m, int n) {
    if (m <= 0 || n <= 0)
        throw exception();

    linii = m;
    coloane = n;
    rad = nullptr;
}

// O(np), np - nr de noduri din subarborele cu radacina p
void Matrice::distruge(Nod* p) {
    if (p != nullptr) {
        distruge(p->st);
        distruge(p->dr);
        delete p;
    }
}

// O(n), n - nr de noduri
Matrice::~Matrice() {
    distruge(rad);
}

// Theta(1)
int Matrice::nrLinii() const {
    return linii;
}

// Theta(1)
int Matrice::nrColoane() const {
    return coloane;
}

// O(h), h - inaltimea arborelui
TElem Matrice::element(int i, int j) const {
    if (i < 0 || i >= linii || j < 0 || j >= coloane)
        throw exception();

    Nod* p = rad;

    while (p != nullptr) {
        if (i == p->linie && j == p->coloana)
            return p->valoare;

        if (i < p->linie || (i == p->linie && j < p->coloana))
            p = p->st;
        else
            p = p->dr;
    }

    return NULL_TELEMENT;
}

// O(h), h - inaltimea arborelui
Matrice::Nod* Matrice::minim(Nod* p) {
    while (p->st != nullptr)
        p = p->st;

    return p;
}

int Matrice::min_max(){
    if(this->rad == nullptr){
        throw exception();
    }

    return max(this->rad) - min(this->rad);
}

int Matrice::min(Nod* p){
    if(p->dr == nullptr && p->st == nullptr){
        return p->valoare;
    }

    int st,dr;

    if(p->dr == nullptr){
        dr = this->rad->valoare;
    }
    else{
        dr = min(p->dr);
    }

    if(p->st == nullptr){
        st = this->rad->valoare;
    }
    else{
        st = min(p->st);
    }

    int mini;
    if(st < p->valoare) mini = st;
    else mini = p->valoare;

    if(dr < mini) mini = dr;

    return mini;
}

int Matrice::max(Nod* p){
    if(p->dr == nullptr && p->st == nullptr){
        return p->valoare;
    }

    int st,dr;

    if(p->dr == nullptr){
        dr = -this->rad->valoare;
    }
    else{
        dr = max(p->dr);
    }

    if(p->st == nullptr){
        st = -this->rad->valoare;
    }
    else{
        st = max(p->st);
    }

    int mini;
    if(st > p->valoare) mini = st;
    else mini = p->valoare;

    if(dr > mini) mini = dr;

    return mini;
}


// O(h), h - inaltimea arborelui
Matrice::Nod* Matrice::sterge(Nod* p, int i, int j) {
    if (p == nullptr)
        return nullptr;

    if (i < p->linie || (i == p->linie && j < p->coloana)) {
        p->st = sterge(p->st, i, j);
        return p;
    }

    if (i > p->linie || (i == p->linie && j > p->coloana)) {
        p->dr = sterge(p->dr, i, j);
        return p;
    }


    if (p->st == nullptr) {
        Nod* aux = p->dr;
        delete p;
        return aux;
    }

    if (p->dr == nullptr) {
        Nod* aux = p->st;
        delete p;
        return aux;
    }

    Nod* succ = minim(p->dr);

    p->linie = succ->linie;
    p->coloana = succ->coloana;
    p->valoare = succ->valoare;

    p->dr = sterge(p->dr, succ->linie, succ->coloana);

    return p;
}

// O(h), h - inaltimea arborelui
TElem Matrice::modifica(int i, int j, TElem e) {
    if (i < 0 || i >= linii || j < 0 || j >= coloane)
        throw exception();

    Nod* p = rad;
    Nod* parinte = nullptr;

    while (p != nullptr) {
        if (i == p->linie && j == p->coloana) {
            TElem vechi = p->valoare;

            if (e == NULL_TELEMENT)
                rad = sterge(rad, i, j);
            else
                p->valoare = e;

            return vechi;
        }

        parinte = p;

        if (i < p->linie || (i == p->linie && j < p->coloana))
            p = p->st;
        else
            p = p->dr;
    }

    if (e == NULL_TELEMENT)
        return NULL_TELEMENT;

    Nod* nou = new Nod(i, j, e);

    if (parinte == nullptr) {
        rad = nou;
    } else if (i < parinte->linie || (i == parinte->linie && j < parinte->coloana)) {
        parinte->st = nou;
    } else {
        parinte->dr = nou;
    }

    return NULL_TELEMENT;
}