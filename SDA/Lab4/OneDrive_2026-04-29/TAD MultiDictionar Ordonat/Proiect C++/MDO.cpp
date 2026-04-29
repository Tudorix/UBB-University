#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;

MDO::MDO(Relatie r) {
	this->r = r;
	this->prim = nullptr;
	this->ultim = nullptr;
	this->dimensiune = 0;
}


void MDO::adauga(TCheie c, TValoare v) {
	if(this->prim == nullptr)
	{
		//Nod Dictionar
		Nod_dict* nod = new Nod_dict;
		nod->cheie = c;
		nod->next = nullptr;
		nod->prev = nullptr;
		
		nod->valori.push_back(v);

		this->prim = nod;
		this->ultim = nod;
		this->dimensiune++;
	}else{
		Nod_dict* nod = this->prim;
		while(nod != nullptr && nod->cheie != c && this->r(nod->cheie, c))
		{
    		nod = nod->next;
		}

		if(nod != nullptr && nod->cheie == c)
		{
			nod->valori.push_back(v);
			this->dimensiune++;
		}else{
			//Nod Dictionar
			Nod_dict* nod_nou = new Nod_dict;
			nod_nou->cheie = c;
			nod_nou->next = nullptr;
			nod_nou->prev = nullptr;
			nod_nou->valori.push_back(v);

			if(nod == this->prim)
			{
				nod_nou->next = this->prim;
				this->prim->prev = nod_nou;
				this->prim = nod_nou;
			}else if(nod == nullptr)
			{
				this->ultim->next = nod_nou;
				nod_nou->prev = this->ultim;
				this->ultim = nod_nou;
			}else{
				nod_nou->next = nod;
				nod_nou->prev = nod->prev;
				nod->prev->next = nod_nou;
				nod->prev = nod_nou;
			}

			this->dimensiune++;
		}
	}
}

vector<TValoare> MDO::cauta(TCheie c) const {
	Nod_dict* nod = this->prim;
	while(nod != nullptr && nod->cheie != c)
	{
		nod = nod->next;
	}
	return nod != nullptr ? nod->valori : vector<TValoare>();
}

bool MDO::sterge(TCheie c, TValoare v) {
	Nod_dict* nod = this->prim;
	while(nod != nullptr && nod->cheie != c)
	{
		nod = nod->next;
	}		

	if(nod != nullptr){
		for(int i = 0; i < nod->valori.size();i++){
			if(nod->valori[i] == v){
				nod->valori.erase(nod->valori.begin() + i);
				this->dimensiune--;

				if(nod->valori.size() == 0)
				{
					if(nod == this->prim && nod == this->ultim)
					{
						this->prim = nullptr;
						this->ultim = nullptr;
					}else if(nod == this->prim)
					{
						this->prim = nod->next;
						this->prim->prev = nullptr;
					}else if(nod == this->ultim)
					{
						this->ultim = nod->prev;
						this->ultim->next = nullptr;
					}else{
						nod->prev->next = nod->next;
						nod->next->prev = nod->prev;
					}
					delete nod;
				}

				return true;
			}
		}
	}
	return false;
}

int MDO::dim() const {
	return this->dimensiune;
	return 0;
}

bool MDO::vid() const {
	return dimensiune == 0;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	Nod_dict* nod = this->prim;
	while(nod != nullptr)
	{
		Nod_dict* nod_stept = nod->next;
		delete nod;
		nod = nod_stept;
	}
}
