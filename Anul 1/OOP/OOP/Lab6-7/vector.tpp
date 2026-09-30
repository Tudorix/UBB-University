/*#include "vector.h"

template<typename T>
vector<T>::vector()
{
    this->capacitate = 5;
    this->len = 0;
    this->elems = new T[capacitate];
}

template<typename T>
vector<T>::vector(const vector<T>& other) {
    this->capacitate = other.capacitate;
    this->len = other.len;

    this->elems = new T[capacitate];

    for (int i = 0; i < len; i++)
        elems[i] = other.elems[i];
}

template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& other) {
    if (this == &other)
        return *this;

    delete[] elems;

    capacitate = other.capacitate;
    len = other.len;

    elems = new T[capacitate];

    for (int i = 0; i < len; i++) {
        elems[i] = other.elems[i];
    }

    return *this;
}

template<typename T>
T& vector<T>::operator[](int index) {
    return elems[index];
}

template<typename T>
long unsigned int vector<T>::size(){
    return (long unsigned int)this->len;
}

template<typename T>
void vector<T>::push_back(T elem){
    if(this->len == this->capacitate){
        // Resize 
        this->capacitate *= 2;

        T *newElems = new T[capacitate];
        for(int i = 0; i < this->capacitate / 2; i++){
            newElems[i] = elems[i];
        }
        delete[] elems;
        this->elems = newElems;
    }

    this->elems[len] = elem;
    this->len++;
}
        
template<typename T>
void vector<T>::erase(int index) {
    for (int i = index; i < len - 1; i++) {
        elems[i] = elems[i + 1];
    }
    len--;
}

template<typename T>
vector<T>::~vector()
{
    delete[] this->elems;
}
*/