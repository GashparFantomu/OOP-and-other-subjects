#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Clasa de bază
class Animal {
public:
    virtual void speak() const {
        cout << "Animal face un sunet generic\n";
    }
    virtual ~Animal() {}  // Destructor virtual pentru siguranță
};

// Clasa derivată 1
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Câine: Ham ham!\n";
    }
};

// Clasa derivată 2
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Pisică: Miau miau!\n";
    }
};

int main() {
    // Creăm un container de pointeri la Animal
    Animal* cat = new Cat();
    Animal* doggo = new Dog();
    Animal* aninal = new Animal();
    cat->speak();
    doggo->speak();
    aninal->speak();

    delete cat;
    delete doggo;
    delete aninal;
    return 0;
}
