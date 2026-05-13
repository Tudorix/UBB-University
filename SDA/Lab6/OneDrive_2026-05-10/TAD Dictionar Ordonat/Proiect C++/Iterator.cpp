#include "Iterator.h"
#include "DO.h"
#include <exception>
#include <vector>
using namespace std;

Iterator::Iterator(const DO& d) : dict(d) {
    prim();
}

void Iterator::prim() {
    curenti.clear();

    for(int i = 0; i < dict.capacitate; i++) {
        curenti.push_back(dict.poz[i]);
    }

    p = nullptr;
    index = -1;

    for(int i = 0; i < dict.capacitate; i++) {
        if(curenti[i] != nullptr) {
            if(p == nullptr || dict.rel(curenti[i]->c, p->c)) {
                p = curenti[i];
                index = i;
            }
        }
    }
}

void Iterator::urmator() {
    if(!valid())
        throw exception();

    curenti[index] = curenti[index]->urm;

    p = nullptr;
    index = -1;

    for(int i = 0; i < dict.capacitate; i++) {
        if(curenti[i] != nullptr) {
            if(p == nullptr || dict.rel(curenti[i]->c, p->c)) {
                p = curenti[i];
                index = i;
            }
        }
    }
}

bool Iterator::valid() const {
    return p != nullptr;
}

TElem Iterator::element() const {
    if (!valid())
        throw exception();

    return {p->c, p->v};
}