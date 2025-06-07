#pragma once
#include <iostream>
using namespace std;

class ClasaB; // Declarație anticipată

class ClasaA {
private:
    int secret = 100;

    friend class ClasaB; // ClasaB este prietenă cu ClasaA
};

class ClasaB {
public:
    void afiseaza(ClasaA a) {
        cout << "Secretul este: " << a.secret << endl;
    }
};

int main() {
    ClasaA a;
    ClasaB b;
    b.afiseaza(a);
    return 0;
}
