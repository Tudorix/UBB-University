#include "IteratorMDO.h"
#include "MDO.h"

IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
    prim();
}

void IteratorMDO::prim() {
    nod_curent = dict.prim;
    index_valori = 0;
}

void IteratorMDO::urmator() {
    if (!valid()) {
        throw exception();
    }

    index_valori++;

    if (index_valori >= dict.elems[nod_curent].valori.size()) {
        nod_curent = dict.urm[nod_curent];
        index_valori = 0;
    }
}

bool IteratorMDO::valid() const {
    return nod_curent != -1 &&
        index_valori < dict.elems[nod_curent].valori.size();
}

TElem IteratorMDO::element() const {
    if (!valid()) {
        throw exception();
    }

    return make_pair(
        dict.elems[nod_curent].cheie,
        dict.elems[nod_curent].valori[index_valori]
    );
}

// O(k)
void IteratorMDO::avanseazaKPasi(int k){
	int i = 0;
	while(i < k){
		urmator();
	}
}