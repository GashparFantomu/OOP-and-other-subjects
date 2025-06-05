#pragma once
#include <iostream>
using namespace std;

class Base {
protected:
    int x;
public:
    Base(int x)  {
        this->x = x;
    }
    void setX(int x) {
        this->x = x;
    }
    void show() const {
        cout << "Base x = " << x << endl;
    }
};

class Derived : public Base {
    int y;
public:
    Derived(int x, int y) : Base(x) {
        this->y = y;
    }

    void setY(int y) {
        this->y = y;
    }

    void show() const {
        Base::show(); // apel explicit al metodei din baza
        cout << "Derived y = " << y << endl;
    }
};

int main() {
    Derived obj(10, 20);
    obj.setX(100);  // folosind this->x în clasa de bază
    obj.setY(200);  // folosind this->y în clasa derivată
    obj.show();
}
