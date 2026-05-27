#include "Matrice.h"
#include <exception>

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