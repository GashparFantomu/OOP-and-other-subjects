#pragma once
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() const = 0{
        cout << "Sunt Base\n";
    }
};

class Derived : public Base {
public:
    void show() const override {
        cout << "Sunt Derived\n";
    }
};

int main() {
    cout << "--- Obiect direct ---\n";
    Derived d1;
    d1.show();  // Apelez direct Base::show

    cout << "\n--- Pointer la baza cu instanta derivata ---\n";
    Base* ptr = new Derived();
    ptr->show();  // POLIMORFISM – se apeleaza Derived::show
    delete ptr;

    cout << "\n--- Referinta la baza cu instanta derivata ---\n";
    Derived d2;
    Base& ref = d2;
    ref.show();  // POLIMORFISM – se apeleaza Derived::show

    return 0;
}
