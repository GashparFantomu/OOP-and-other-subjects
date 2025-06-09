#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;


class MyException : public exception {
    string msg;
public:
    MyException(const string& m){
        msg = m;
    }
    const char* what() const noexcept override {
        return msg.c_str();
    }
};

int main() {
    try {
        throw MyException("Asta e eroarea mea!");
    }
    catch (const MyException& e) {
        cout << "Prins MyException: " << e.what() << "\n";
    }
    catch (const exception& e) {
        cout << "Prins exception: " << e.what() << "\n";
    }

}
