//
// Created by tudorix on 17.05.2026.
//

#ifndef SUBSIM_ROCHIE_H
#define SUBSIM_ROCHIE_H
#include <string>

using namespace std;
class Rochie {
    private:
        int id;
        string name;
        int size, price;
        bool avaliable;
    public:
        Rochie(int id, string name,int size, int price, bool avalable);

        int get_id() const {
            return id;
        }

    string get_name() const {
            return name;
        }

    int get_price() const {
            return price;
        }

    int get_size() const {
            return size;
        }

    bool get_avaliable() const {
            return avaliable;
        }

    void set_avaliable(bool state) {
             avaliable = state;
        }
};

#endif //SUBSIM_ROCHIE_H
