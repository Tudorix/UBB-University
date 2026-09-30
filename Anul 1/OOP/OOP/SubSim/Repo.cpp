#include "Repo.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <sstream>

Repo::Repo(string const &filename) {
    fn = filename;
    rochie.clear();
}

void Repo::add(Rochie const &rochie) {
    this->rochie.push_back(rochie);
}

int Repo::get_by_name(string const &name) {
    int id  = -1;
    for (auto const &it : rochie) {
        if (it.get_name() == name) {
            id = it.get_id();
            return id;
        }
    }
    throw std::logic_error("No such repo");
}

void Repo::wr() {
    ofstream fout(fn);
    for (auto const &it : rochie) {
        fout << it.get_id() << "," << it.get_name() << "," << it.get_size() << "," << it.get_price() << ",";
        if (it.get_avaliable()) fout << "True" << endl;
        else fout << "False" << endl;
    }
}

void Repo::rd() {
    rochie.clear();
    ifstream fin(fn);

    string line;

    while (getline(fin, line)) {
        stringstream ss(line);

        string id_s, name, size_s, price_s, available_s;

        getline(ss, id_s, ',');
        getline(ss, name, ',');
        getline(ss, size_s, ',');
        getline(ss, price_s, ',');
        getline(ss, available_s, ',');

        int id = stoi(id_s);
        int size = stoi(size_s);
        int price = stoi(price_s);
        bool available = available_s == "True";

        Rochie r(id, name, size, price, available);
        rochie.push_back(r);
    }
    qDebug() << this->rochie.size();

    fin.close();
}



vector<Rochie>& Repo::get_all() {
    return this->rochie;
}
