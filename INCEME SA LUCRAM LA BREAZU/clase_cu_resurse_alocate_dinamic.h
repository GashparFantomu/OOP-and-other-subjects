#pragma once
#include <iostream>
using namespace std;

class Vector {
    int* data;
    int size;
public:
    Vector(int n) {
        size = n;
        data = new int[n]; // alocare dinamică
    }

    ~Vector() {
        delete[] data; // eliberare memorie
    }

    // Constructor de copiere
    Vector(const Vector& other) {
        size = other.size;
        data = new int[size];
        copy(other.data, other.data + size, data);
    }

    // Operator de atribuire
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            copy(other.data, other.data + size, data);
        }
        return *this;
    }
};
