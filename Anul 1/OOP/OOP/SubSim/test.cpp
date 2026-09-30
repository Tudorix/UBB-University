//
// Created by tudorix on 17.05.2026.
//

#include "test.h"

#include <QWidget>

#include "Repo.h"
#include "Service.h"
#include "Rochie.h"
#include <cassert>

test::test(Service *service, Repo *repo) {
    this->service = service;
    this->repo = repo;
    reset();
    test_load_file();
    test_rent();
    test_sort();
    test_error();
}

void test::test_load_file() {
    vector<Rochie> o = service->get_all();
    assert(o.size() == 5);

    Rochie r = o[0];
    assert(r.get_id() == 1);
    assert(r.get_price() == 9000);
    assert(r.get_name() == "GUCCI WOOL DRESS");
    assert(r.get_size() == 40);
    assert(r.get_avaliable() == 1);
}

void test::test_rent() {
    int id = service->find_by_name("GUCCI WOOL DRESS");
    service->rent(1);

    vector<Rochie> o = service->get_all();
    assert(o.size() == 5);

    Rochie r = o[0];
    assert(r.get_id() == 1);
    assert(r.get_price() == 9000);
    assert(r.get_name() == "GUCCI WOOL DRESS");
    assert(r.get_size() == 40);
    assert(r.get_avaliable() == 0);
}

void test::test_sort() {
    // Sort Pret
    vector<Rochie> o = service->sort_pret();
    assert(o.size() == 5);
    for (unsigned int i = 0; i < o.size() - 1; i++) {
        assert(o[i].get_price() < o[i + 1].get_price());
    }
    // Sort Size
    o = service->sort_marime();
    assert(o.size() == 5);
    for (unsigned int i = 0; i < o.size() - 1; i++) {
        assert(o[i].get_size() < o[i + 1].get_size());
    }
}

void test::test_error() {
    try {
        service->rent(999);
        assert(false);
    } catch (...) {
        assert(true);
    }

    try {
        service->rent(3); // deja False în CSV
        service->rent(3); // deja False în CSV
        assert(false);
    } catch (...) {
        assert(true);
    }

    try {
        service->find_by_name("Test Nu exista");
        service->find_by_name("99999999999");
        assert(false);
    } catch (...) {
        assert(true);
    }
}
