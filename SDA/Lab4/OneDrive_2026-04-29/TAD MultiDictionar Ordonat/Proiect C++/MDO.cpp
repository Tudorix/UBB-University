#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

// Theta(1)
MDO::MDO(Relatie r) {
    this->r = r;
    capacitate = 10;
    len = 0;

    elems = new NodChei[capacitate];
    urm = new int[capacitate];
    ant = new int[capacitate];

    prim = -1;
    ultim = -1;
    primLiber = 0;

    for (int i = 0; i < capacitate - 1; i++) {
        urm[i] = i + 1;
        ant[i] = -1;
    }

    urm[capacitate - 1] = -1;
    ant[capacitate - 1] = -1;
}

int MDO::aloca() {
    int poz = primLiber;
    primLiber = urm[primLiber];
    return poz;
}

void MDO::dealoca(int i) {
    urm[i] = primLiber;
    primLiber = i;
}

void MDO::redim() {
    int capVeche = capacitate;
    int capNoua = capacitate * 2;

    NodChei* elemsNou = new NodChei[capNoua];
    int* urmNou = new int[capNoua];
    int* antNou = new int[capNoua];

    for (int i = 0; i < capVeche; i++) {
        elemsNou[i] = elems[i];
        urmNou[i] = urm[i];
        antNou[i] = ant[i];
    }

    for (int i = capVeche; i < capNoua - 1; i++) {
        urmNou[i] = i + 1;
        antNou[i] = -1;
    }

    urmNou[capNoua - 1] = -1;
    antNou[capNoua - 1] = -1;

    primLiber = capVeche;

    delete[] elems;
    delete[] urm;
    delete[] ant;

    elems = elemsNou;
    urm = urmNou;
    ant = antNou;
    capacitate = capNoua;
}

// O(n)
void MDO::adauga(TCheie c, TValoare v) {
	int curent = prim;

    while (curent != -1 && r(elems[curent].cheie, c)) {
        if (elems[curent].cheie == c) {
            elems[curent].valori.push_back(v);
            len++;
            return;
        }
		curent = urm[curent];
    }
	
	if(primLiber == -1){
		redim();
	}

    int nou = aloca();

    elems[nou].cheie = c;
    elems[nou].valori.clear();
    elems[nou].valori.push_back(v);

    urm[nou] = -1;
    ant[nou] = -1;

	if (prim == -1) {
        prim = ultim = nou;
        len++;
        return;
    }

    if (curent == prim) {
        urm[nou] = prim;
        ant[prim] = nou;
        prim = nou;
    }
    else if (curent == -1) {
        ant[nou] = ultim;
        urm[ultim] = nou;
        ultim = nou;
    }
    else {
        int anterior = ant[curent];

        urm[anterior] = nou;
        ant[nou] = anterior;

        urm[nou] = curent;
        ant[curent] = nou;
    }

    len++;

}

// O(n)
vector<TValoare> MDO::cauta(TCheie c) const {
    int poz = prim;

    while (poz != -1) {
        if (elems[poz].cheie == c) {
            return elems[poz].valori;
        }
        poz = urm[poz];
    }

    return vector<TValoare>(); // nu exista cheia
}

// O(m) - unde m = nr de perechi (cheie,valoare)
bool MDO::sterge(TCheie c, TValoare v) {
	int poz = prim;

    while (poz != -1 && elems[poz].cheie != c) {
        poz = urm[poz];
    }

    if (poz == -1)
        return false;

    auto& vec = elems[poz].valori;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == v) {
            vec.erase(vec.begin() + i);
            len--;

            if (vec.empty()) {

                if (poz == prim && poz == ultim) {
                    prim = ultim = -1;
                }
                else if (poz == prim) {
                    prim = urm[poz];
                    ant[prim] = -1;
                }
                else if (poz == ultim) {
                    ultim = ant[poz];
                    urm[ultim] = -1;
                }
                else {
                    urm[ant[poz]] = urm[poz];
                    ant[urm[poz]] = ant[poz];
                }

                dealoca(poz);
            }

            return true;
        }
    }

    return false;
}

//Theta(1)
int MDO::dim() const {
	return this->len;
	return 0;
}

//Theta(1)
bool MDO::vid() const {
	return len == 0;
}

//Theta(1)
IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

// Theta(1)
MDO::~MDO() {
	delete[] elems;
    delete[] urm;
    delete[] ant;
}
