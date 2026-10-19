#include "Produs.h"

Produs::Produs(int ID ,int pret, string nume, string tip, string producator) {
    /**
    * Constructor pentru Produs
    * 
    * @param ID(int) - ID-ul
    * @param pret(int) - pretul
    * @param nume(string) - numele
    * @param tip(string) - tipul
    * @param producator(string) - producatorul
    */
    this->ID = ID;
    this->pret = pret;
    this->nume = nume;
    this->tip = tip;
    this->producator = producator;
}

    int Produs::getID() {
        /**
         * Getter pentru ID
         */
        return ID;
    }

    int Produs::getPret() {
        /**
         * Getter pentru pret
         */
        return pret;
    }

    string Produs::getNume() {
        /**
         * Getter pentru nume
         */
        return nume;
    }

    string Produs::getTip() {
        /**
         * Getter pentru tip
         */
        return tip;
    }

    string Produs::getProducator() {
        /**
         * Getter pentru producator
         */
        return producator;
    }

    void Produs::afiseaza() {
        /**
         * Functie de afisare
         */
        cout << "ID: " << ID << " ; ";
        cout << "Nume: " << nume << " ; ";
        cout << "Pret: " << pret << " ; ";
        cout << "Tip: " << tip << " ; ";
        cout << "Producator: " << producator << endl;
    }