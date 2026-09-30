//
// Created by tudorix on 17.05.2026.
//

#ifndef SUBSIM_TEST_H
#define SUBSIM_TEST_H
#include "Repo.h"
#include "Service.h"

class test {
    private:
    Service *service;
    Repo *repo;
    void test_load_file();
    void test_rent();

    void reset() {
        Rochie r(1,"GUCCI WOOL DRESS",40,9000,1);
        repo->add(r);
        r = Rochie(2,"Nume 2",30,8000,0);
        repo->add(r);
        r = Rochie(3,"Nume 3",50,6000,1);
        repo->add(r);
        r = Rochie(4,"Nume 4",70,30,1);
        repo->add(r);
        r = Rochie(5,"Nume 8",10,7000,1);
        repo->add(r);
        repo->wr();

    }

    void test_sort();
    void test_error();

    public:
    test(Service *service, Repo *repo);
};


#endif //SUBSIM_TEST_H
