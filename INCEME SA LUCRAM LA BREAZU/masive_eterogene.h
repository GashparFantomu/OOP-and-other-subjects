#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Clasa de bază
class Animal {
public:
    virtual void speak() const {
        cout << "Animal generic\n"; //metoda virtuala obisnuita
    }
    virtual ~Animal() {}
};

// Clase derivate
class Dog : public Animal {
public:
    void speak() const override {
        cout << "Dog: Ham ham nigga!\n";
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat: Miau nigga!\n";
    }
};

class Bird : public Animal {
public:
    void speak() const override {
        cout << "Bird: Cirip cirip in pula mea!\n";
    }
};

int main() {
    // 1. Creăm un “masiv eterogen” de animale
    vector<Animal*> zoo;
    zoo.push_back(new Dog());
    zoo.push_back(new Cat());
    zoo.push_back(new Bird());
    zoo.push_back(new Animal());

    Animal* cat = new Cat();
    cat->speak();


    // 2. Tratăm uniform tot containerul
    for (Animal* a : zoo) {
        a->speak();  // apel virtual → fiecare obiect răspunde cu propriul “speak”
    }

    // 3. Curățare
    for (Animal* a : zoo) delete a;
    return 0;
}
//yea... thats it...