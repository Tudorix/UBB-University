//
// Created by tudorix on 20.05.2026.
//

#ifndef SIMUL_TEST_H
#define SIMUL_TEST_H
#include <iostream>
#include  "Service.h"

using namespace std;

class test {
private:
        Service service;
    public:
        test(Service service);

        void testReadFromFile();
};


#endif //SIMUL_TEST_H
