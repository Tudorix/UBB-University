#include <iostream>
#include <string>
using namespace std;

class Produs {
private:
    int ID;
    int pret;
    string nume;
    string tip;
    string producator;

public:
    Produs(int ID ,int pret, string nume, string tip, string producator);
    int getPret();
    int getID();
    string getNume();
    string getTip();
    string getProducator();
    void afiseaza();
};