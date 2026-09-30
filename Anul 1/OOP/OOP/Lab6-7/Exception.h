#pragma once
#include <iostream>
#include <exception>
using namespace std;

class Except : public exception {
private:
    const char* mes;

public:
    Except(const char* mes){
        this->mes = mes;
    }

    const char* what() const noexcept override{
        return mes;
    }
};
