/*#pragma once
#include <iostream>
#include "Produs.h"

template<typename T> class vector
{
    private:
        int capacitate;
        int len;
        T *elems;
        
    public:
        // Constructori
        vector();
        vector(const vector<T>& other);

        //Operator
        T& operator[](int index);
        vector<T>& operator=(const vector<T>& other);

        long unsigned int size();
        void push_back(T);
        void erase(int index);

        ~vector();
};

#include "vector.tpp"
*/