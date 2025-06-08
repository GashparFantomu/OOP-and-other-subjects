#pragma once
#include <iostream>

using namespace std;

struct Student {
    string nume;
    int varsta;
};

int main() {
    cout << "1) Constructor implicit + copiere:\n";
    Student a = { "Ana", 20 };   // inițializare
    Student b = a;             // constructor de copiere (implicit)

    cout << "a.nume = " << a.nume << ", b.nume = " << b.nume << "\n";

    cout << "\n2) Operator de atribuire (implicit):\n";
    Student c = { "Bogdan", 22 };
    c = a;                     // operator de atribuire (implicit)

    cout << "c.nume = " << c.nume << ", c.varsta = " << c.varsta << "\n";

    return 0;
}
