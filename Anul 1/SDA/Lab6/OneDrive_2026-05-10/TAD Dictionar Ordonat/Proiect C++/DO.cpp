#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

// Theta(1)
TCheie DO::disp(TCheie c) const{
	return abs(c) % capacitate;
}

// Theta(n)
DO::DO(Relatie r) {
    rel = r;
    len = 0;
    capacitate = 10;

    for(int i = 0; i < capacitate; i++){
        poz[i] = nullptr;
    }
}

// O(max(mi)) - mi - nr de valori din listele independente
TValoare DO::adauga(TCheie c, TValoare v) {
	TCheie loc = disp(c);
	Nod* n = poz[loc];

	// Daca e primu
	if(n == nullptr){
		Nod* q = new Nod;
		q->c = c;
		q->v = v;
		q->urm = nullptr;
		poz[loc] = q;
		len++;
	}else{
		Nod *prec = nullptr;
		while(n != nullptr && rel(n->c,c)){
			if(n->c == c) break;
			prec = n;
			n = n->urm;
		}

		if(n != nullptr && n == poz[loc] && n->c == c){
			TValoare old = n->v;
    		n->v = v;
    		return old;
		}

		if(n != nullptr && n->c == c){
			TValoare old_val = n->v;
			n->v = v;
			return old_val;
		}else{
			Nod* nou = new Nod;
			nou->v = v;
			nou->c = c;
			
			nou->urm = n;
			if (prec == nullptr)
    			poz[loc] = nou;
			else
    			prec->urm = nou;
			
			len++;
		}
	}
	
	return NULL_TVALOARE;
}

// O(max(mi)) - mi - nr de valori din listele independente
TValoare DO::cauta(TCheie c) const {
	TCheie loc = disp(c);
	Nod* n = poz[loc];

	if(n != nullptr){
		while(n != nullptr && rel(n->c,c)){
			if(n->c == c) break;
			n = n->urm;
		}

		if(n != nullptr && n->c == c){
			return n->v;
		}
	}

	return NULL_TVALOARE;	
}

// O(max(mi)) - mi - nr de valori din listele independente
TValoare DO::sterge(TCheie c) {
	TCheie loc = disp(c);
	Nod* n = poz[loc];

	if(n != nullptr){
		if(n->c == c){
			len--;
			TValoare val = n->v;
			poz[loc] = n->urm;
			delete n;
			return val;
		}

		Nod *prec = nullptr;
		while(n != nullptr && rel(n->c,c)){
			if(n->c == c) break;
			prec = n;
			n = n->urm;
		}

		if(n != nullptr && n->c == c){
			len--;
			prec->urm = n->urm;
			TValoare val = n->v;
			delete n;
			return val;
		}
	}

	return NULL_TVALOARE;
}

// Theta(1)
int DO::dim() const {
	return len;
}

// Theta(1)
bool DO::vid() const {
	return len == 0;
}

// Theta(1)
Iterator DO::iterator() const {
	return  Iterator(*this);
}

// Theta(n * m)
DO::~DO() {
	for(int i = 0; i < capacitate; i++){
		if(poz[i] != nullptr){
			Nod* q = poz[i];
			while(q != nullptr){
				Nod *n = q;
				q = q->urm;
				delete n;
			}
		}
	}
}
