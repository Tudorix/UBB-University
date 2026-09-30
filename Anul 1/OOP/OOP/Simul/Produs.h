//
// Created by tudorix on 20.05.2026.
//

#ifndef SIMUL_PRODUS_H
#define SIMUL_PRODUS_H
#include <string>

using namespace std;

class Produs {
private:
    int cod;
    string name;
    string categoria;
    int year;
    int price;

public:
    // Constructor Produs
    Produs(int cod, string name, string categoria, int year, int price);

    // Getter Functions

    int getCod() {
        return cod;
    };
    string getName() {
        return name;
    }
    string getCategoria() {
        return categoria;
    }
    int getYear() {
        return year;
    }
    int getPrice() {
        return price;
    }

    // Setter Functions

    void setCod(int cod) {
        cod = cod;
    }

    void setName(string name) {
        name = name;
    }

    void setCategoria(string categoria) {
        categoria = categoria;
    }
    void setYear(int year) {
        year = year;
    }
    void setPrice(int price) {
        price = price;
    }

};


#endif //SIMUL_PRODUS_H
