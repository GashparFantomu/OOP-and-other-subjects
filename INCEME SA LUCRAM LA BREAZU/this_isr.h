#pragma once
#include <iostream>
using namespace std;

class CA {
public:
    int x;
    void setX(int x) {
        this->x = x; // membru = parametru
    }
    void afiseaza() {
        cout << "x = " << this->x << endl;
    }
};

int main() {
    CA a;
    a.setX(42);     // În fundal: setX(&a, 42)
    a.afiseaza();   // În fundal: afiseaza(&a)
}
