//
// Created by tudorix on 20.05.2026.
//

#include "test.h"
#include <cassert>

test::test(Service service) : service(service) {
    testReadFromFile();
}

void test::testReadFromFile() {
    vector<Produs> v;
    v = service.getAll();
    assert(v.size() == 10);
    for (auto p : v) {
        assert(p.getCod() != 0);
        assert(p.getName() != "");
        assert(p.getCategoria() != "");
        assert(p.getYear() > -1);
        assert(p.getPrice() > -1);
    }
}