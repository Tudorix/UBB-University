#include "Matrice.h"

#include <exception>
#include <stdexcept>

using namespace std;

// Theta(1)
Matrice::Matrice(int m, int n) {
	if(m < 0 || n < 0){
		throw std::runtime_error("Marimi Invalide");
	}

	this->nrCol = n;
	this->nrLin = m;
	this->prim = nullptr;
	this->ultim = nullptr;
}

// Theta(n)
Matrice::~Matrice(){
	Nod *p = this->prim;
	while(p != nullptr){
		Nod *q = p->urm;
		delete p;
		p = q;
	}
}

// Theta(1)
int Matrice::nrLinii() const{
	return this->nrLin;
	return 0;
}

// Theta(1)
int Matrice::nrColoane() const{
	return this->nrCol;
	return 0;
}

// O(n)
TElem Matrice::element(int i, int j) const{
	if((i >= this->nrLin || j >= this->nrCol) || (i < 0 || j < 0)){
		throw std::runtime_error("Indici Invalizi");
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

// O(n^2)
TElem Matrice::modifica(int i, int j, TElem e) {
	if((i >= this->nrLin || j >= this->nrCol) || (i < 0 || j < 0)){
		throw std::runtime_error("Indici Invalizi");
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
	}else{
		Nod *p = this->prim;

		while(p->linie < i){
			if(p != this->ultim){
				p = p->urm;
			}else{
				break;
			}
		}
		while(p->coloana < j){
			if(p != this->ultim){
				p = p->urm;
			}else{
				break;
			}
		}

		if(p->coloana == j && p->linie == i){
			TElem old = p->valoare;
			p->valoare = e;
			return old;
		}else{
			Nod *q = new Nod();
			q->coloana = j;
			q->linie = i;
			q->valoare = e;

			q->ant = p;
			q->urm = p->urm;
			p->urm = q;

			if(p == this->ultim){
				this->ultim = q;
			}
		}
	}
	return NULL_TELEMENT;
}

// O(m * n^3)
void Matrice::transpusa(){
	int m = this->nrCol;
	int n = this->nrLin;

	int aux[n][m] = {0};

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(aux[i][j] == 0){
				int x = element(i,j);// O(n^2)
				int y = element(j,i);// O(n^2)

				modifica(i,j,y);// O(n^2)
				modifica(j,i,x);// O(n^2)

				aux[i][j] = 1;
				aux[j][i] = 1;
			}
		}
	}
}


