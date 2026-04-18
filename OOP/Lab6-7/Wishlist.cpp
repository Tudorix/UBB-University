#include "Wishlist.h"

Wishlist::Wishlist(vector<Produs> lista){
    /**
     * Constructor Wishlist
     */
    this->lista = lista;
}

vector<Produs> Wishlist::getList(){
    return this->lista;
}

void Wishlist::empty(){
    this->lista.clear();
}

void Wishlist::add(Produs p){
    this->lista.push_back(p);
}

void Wishlist::Export(string fn){
    ofstream fout(fn + ".csv");
    for(long unsigned int i = 0; i < this->lista.size(); i++){
        fout << lista[i].getID() << "," << lista[i].getNume() << "," << lista[i].getPret() << "," << lista[i].getProducator() << "," << lista[i].getTip() << "\n";
    }
}