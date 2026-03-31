#include "Matrice.h"

#include <exception>

using namespace std;


Matrice::Matrice(int m, int n) {
	if(m < 0 || n < 0){
		throw "Marime Invalida";
	}

	this->nrCol = n;
	this->nrLin = m;
	this->prim = nullptr;
	this->ultim = nullptr;
}

Matrice::~Matrice(){
	Nod *p = this->prim;
	while(p != nullptr){
		Nod *q = p->urm;
		delete p;
		p = q;
	}
}

int Matrice::nrLinii() const{
	return this->nrLin;
	return 0;
}


int Matrice::nrColoane() const{
	return this->nrCol;
	return 0;
}


TElem Matrice::element(int i, int j) const{
	if(i >= this->nrLin && j >= this->nrCol){
		throw "Indici invalizi";
	}
	
	Nod *p = this->prim;
	while(p != nullptr){
		if(p->linie == i && p->coloana == j){
			return p->valoare;
		}
		p = p->urm;
	}
	return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem e) {
	if(i >= this->nrLin && j >= this->nrCol){
		throw "Indici invalizi";
	}

	if(prim == nullptr){
		Nod *p = new Nod();
		p->coloana = j;
		p->linie = i;
		p->valoare = e;
		p->ant = nullptr;
		p->urm = nullptr;
		prim = p;
		ultim = p;
	}
	return NULL_TELEMENT;
}


