#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

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
		delete this->elems;
		this->elems = e;
	}

	index = 0;
	if(this->len > 0){
		
		for(int i = 0; i < this->len; i++){
			if(this->elems[i].first > c){
				index = i;
				break;
			}
		}

		for(int i = index; i < this->len; i++){
			this->elems[i + 1] = this->elems[i];
		}
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
	TValoare rez;
	if(this->len > 1){
		for(int i = 0; i < this->len; i++){
			if(this->elems[i].first == c){
				rez = this->elems[i].second;
			}
		}

		for(int i = 0; i < this->len - 1; i++){
			this->elems[i] = this->elems[i + 1];
		}

		this->len -= 1;
		return rez;
	}else if(this->len == 1){
		rez = this->elems[0].second;
		this->len -= 1;
		return rez;
	}
	return NULL_TVALOARE;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
int DO::dim() const {
	return this->len;
}

//verifica daca dictionarul e vid
bool DO::vid() const {
	if(this->len > 0){
		return false;
	}
	return true;
}

Iterator DO::iterator() const {
	return Iterator(*this);
}

DO::~DO() {
	delete this->elems;
}
