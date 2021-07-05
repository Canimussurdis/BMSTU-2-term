#pragma once
#include "class.h"
#include <iostream>

template <typename T>
class M_vector;

template <typename T>
class Iterator //позволяет сделать алгоритм контейнеро-независимым; абстракция, позволяющая представить множество однотипных объектов
{
private:
    M_vector<T> vector{};
    int pos;
public:
    Iterator(M_vector<T> vect){
        vector = vect;
        pos = 0;
    }

    Iterator<T> next() {
        pos++;
        return *this;
    }

    T& value(){
        return vector.get_elem_for_iterator(pos);
    }

    Iterator &operator++(){
        return next();
    }

    T& operator*(){
        return value();
    }

    bool is_end(){
        return pos == vector.get_length();
    }

    bool operator ==(Iterator &b){
        return value() == b.value();
    }

    bool operator !=(Iterator &b){
        return value() != b.value();
    }
};


