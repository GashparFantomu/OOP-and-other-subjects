#pragma once
#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Desenez un cerc\n";
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Desenez un patrat\n";
    }
};

class ShapeFactory {
public:
    static Shape* create(const string& type) {
        if (type == "circle") {
            return new Circle();
        }
        else if (type == "square") {
            return new Square();
        }
        else {
            return nullptr;  // tip necunoscut
        }
    }
};

int main() {
    Shape* s1 = ShapeFactory::create("circle");
    Shape* s2 = ShapeFactory::create("square");

    if (s1) s1->draw();   // “Desenez un cerc”
    if (s2) s2->draw();   // “Desenez un pătrat”

    delete s1;
    delete s2;
}
