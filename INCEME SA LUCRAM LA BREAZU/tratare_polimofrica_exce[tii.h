#pragma once
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "Exceptie generala MyException";
    }
};

class FileException : public MyException {
public:
    const char* what() const noexcept override {
        return "Exceptie legata de fisiere";
    }
};

int main() {
    try {
        throw FileException(); // Aruncam o exceptie derivata
    }
    catch (const MyException& e) {
        cout << "Prins generic: " << e.what() << '\n'; // Tratare polimorfica
    }
}
