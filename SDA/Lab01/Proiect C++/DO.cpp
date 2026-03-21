#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

// Theta(1)
DO::DO(Relatie r) {
	this->capacitate = 10;
	this->len = 0;
	this->elems = new TElem[this->capacitate];
	this->rel = r;
}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare v) {
	int index = -1;
	for(int i = 0; i < this->len; i++){
		if(this->elems[i].first == c){
			index = i;
			break;
		}
	}

	if(index != -1){
		TValoare old = this->elems[index].second;
		this->elems[index].second = v;
		return old;
	}
	
	//Resize
	if(this->len == this->capacitate){
		this->capacitate *= 2;
		TElem *e = new TElem[this->capacitate];

		for(int i = 0; i < this->len; i++){
			e[i] = this->elems[i];
		}

		delete[] this->elems;
		this->elems = e;
	}

	index = this->len;
	for(int i = 0; i < this->len; i++){
		if(!this->rel(this->elems[i].first,c)){
			index = i;
			break;
		}
	}

	for(int i = this->len; i > index; i--){
		this->elems[i] = this->elems[i - 1];
	}

	this->elems[index].first = c;
	this->elems[index].second = v;
	this->len += 1;

	return NULL_TVALOARE;
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
// complexitate O(n)
TValoare DO::cauta(TCheie c) const {
	for(int i = 0; i < this->len; i++){
		if(this->elems[i].first == c){
			return this->elems[i].second;
		}
	}
	return NULL_TVALOARE;	
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
TValoare DO::sterge(TCheie c) {
	 int poz = -1;

    for (int i = 0; i < this->len; i++) {
        if (this->elems[i].first == c) {
            poz = i;
            break;
        }
    }

    if (poz == -1) {
        return NULL_TVALOARE;
    }

    TValoare rez = this->elems[poz].second;

    for (int i = poz; i < this->len - 1; i++) {
        this->elems[i] = this->elems[i + 1];
    }

    this->len--;
    return rez;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
// Theta(1)
int DO::dim() const {
	return this->len;
}

//verifica daca dictionarul e vid
// Theta(1)
bool DO::vid() const {
	if(this->len > 0){
		return false;
	}
	return true;
}

// Theta(1)
Iterator DO::iterator() const {
	return Iterator(*this);
}

// Theta(1)
DO::~DO() {
	delete this->elems;
}
