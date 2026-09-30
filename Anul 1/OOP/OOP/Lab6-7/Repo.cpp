#include "Repo.h"

Repo::Repo(vector<Produs> lista){
    /**
     * Constructor Repo
     * 
     * @param lista - lista de produse
     */
    this->lista = lista;
}

vector<Produs> Repo::getList(){
    /**
     *Getter pt lista de produse
     */
    return this->lista;
}

void Repo::addRepo(Produs p){
    /**
     * Functie care adauga produs in lista
     * 
     * @param p(Produs) - produsul de adaugat
     */
    this->lista.push_back(p);
}

int Repo::findById(int id){
    /**
     * Functie care gaseste produs in lista
     * 
     * @param id(int)
     * 
     * @return int
     */
    int i = 0;
    for(auto l : this->lista){
        if(l.getID() == id){
            return i;
        }
        i++;
    }
    return -1;
}

void Repo::delRepo(int index){
    /**
     * Functie care sterge produs din lista
     * 
     * @param index(int)
     */

    this->lista.erase(this->lista.begin() + index);
}