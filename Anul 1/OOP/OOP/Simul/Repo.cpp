//
// Created by tudorix on 20.05.2026.
//

#include "Repo.h"
#include <fstream>
#include <qguiapplication_platform.h>
#include <string>
#include <sstream>

#include "Produs.h"

Repo::Repo(string fn) {
    this->fn = fn;
    this->lista.clear();
}

vector<Produs>& Repo::getAll() {
    return this->lista;
}

void Repo::readFromFile() {
    this->lista.clear();
    ifstream fin(this->fn);
    string line;

    while (getline(fin, line)) {
        stringstream linestream(line);

        string cod_s ,name_s, categories_s, year_s, price_s;

        getline(linestream, cod_s, ',');
        getline(linestream, name_s, ',');
        getline(linestream, categories_s, ',');
        getline(linestream, year_s, ',');
        getline(linestream, price_s, ',');

        int id = stoi(cod_s);
        int year = stoi(year_s);
        int price = stoi(price_s);

        Produs p(id,name_s,categories_s,year,price);
        qDebug() << p.getCod();
        this->lista.push_back(p);
    }
}