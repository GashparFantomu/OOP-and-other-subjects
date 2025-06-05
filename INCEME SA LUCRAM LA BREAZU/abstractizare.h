#pragma once
#include <iostream>
using namespace std;

// Clasă abstractă
class Shape { //Interfață comună: oferă setul minim de metode pe care trebuie să le respecte toate clasele derivate.
public:
    // metodă pur virtuală → Shape este abstractă
    virtual void draw() const = 0; 
    virtual ~Shape() {}
};

// Clase derivate
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Desenez cerc\n";
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Desenez pătrat\n";
    }
};

int main() {
    // Shape s;        // ❌ eroare: Shape e abstractă
    Shape* c = new Circle();
    Shape* s = new Square();

    c->draw();  // apel polimorfic → Circle::draw
    s->draw();  // apel polimorfic → Square::draw

    delete c;
    delete s;
    return 0;
}
//yea... again... thats pretty much it