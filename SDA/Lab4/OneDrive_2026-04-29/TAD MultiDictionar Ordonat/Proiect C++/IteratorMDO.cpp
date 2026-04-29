#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d){
	this->nod_curent = this->dict.prim;
	this->index_valori = 0;
}

void IteratorMDO::prim(){
	this->nod_curent = this->dict.prim;
	this->index_valori = 0;
}

void IteratorMDO::urmator(){
	if(!valid())
	{
		throw exception();
	}

	this->index_valori++;
	if(this->index_valori >= this->nod_curent->valori.size())
	{
		this->nod_curent = this->nod_curent->next;
		this->index_valori = 0;
	}
}

bool IteratorMDO::valid() const{
	if(this->nod_curent != nullptr && this->index_valori < this->nod_curent->valori.size())
	{
		return true;
	}
	return false;
}

TElem IteratorMDO::element() const{
	if(!valid())
	{
		throw exception();
	}
	return pair <TCheie, TValoare>  (this->nod_curent->cheie, this->nod_curent->valori[this->index_valori]);
}


