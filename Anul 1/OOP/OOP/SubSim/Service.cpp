#include "Service.h"

#include <algorithm>
#include <stdexcept>

vector<Rochie>& Service::get_all() {
    repo.rd();
    return repo.get_all();
}

vector<Rochie> Service::sort_marime() {
    vector<Rochie> o = repo.get_all();
    sort(o.begin(), o.end(),[](Rochie const &r1, Rochie const &r2) {
        return r1.get_size() < r2.get_size();
    });
    return o;
}

vector<Rochie> Service::sort_pret() {
    vector<Rochie> o = repo.get_all();
    sort(o.begin(), o.end(),[](Rochie const &r1, Rochie const &r2) {
        return r1.get_price() < r2.get_price();
    });
    return o;
}

void Service::rent(int id) {
    auto& o = repo.get_all();
    for (unsigned int i = 0; i < o.size(); i++) {
        if (o[i].get_id() == id) {
            if (o[i].get_avaliable()) {
                o[i].set_avaliable(false);
                this->repo.wr();
                return;
            }else
                throw std::invalid_argument("Not a valid Rochie");
        }
    }
    throw std::invalid_argument("Rochie not found");
}

int Service::find_by_name(string name) {
    return repo.get_by_name(name);
}