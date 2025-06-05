#pragma once
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructor A\n"; }
    int x;
};

class B : virtual public A {
public:
    B() { cout << "Constructor B\n"; }
};

class C : virtual public A {
public:
    C() { cout << "Constructor C\n"; }
};

class D : public B, public C {
public:
    D() { cout << "Constructor D\n"; }
};

int main() {
    D obj;
    obj.x = 42;
    cout << "Valoarea lui x: " << obj.x << "\n";
    return 0;
}