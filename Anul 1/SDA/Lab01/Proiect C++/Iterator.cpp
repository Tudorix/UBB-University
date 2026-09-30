#include "Iterator.h"
#include "DO.h"

using namespace std;

Iterator::Iterator(const DO& d) : dict(d){
	this->curent = 0;
}

void Iterator::prim(){
	this->curent = 0;
}

void Iterator::urmator(){
	this->curent += 1;
}

bool Iterator::valid() const{
	return this->curent < dict.dim();
}

TElem Iterator::element() const{
	if(valid()){
		return this->dict.elems[curent];
	}
	return pair <TCheie, TValoare>  (-1, -1);
}