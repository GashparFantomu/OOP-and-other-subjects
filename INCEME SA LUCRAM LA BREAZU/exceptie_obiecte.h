#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;


class MyException : public exception {
    string msg;
public:
    MyException(const string& m){ //te folosesti de constructor pentru  mesajul de eroare
        msg = m;
    }
    const char* what() const noexcept override {
        return msg.c_str(); 
    }//echivalentu lui printStackTrace() din Java
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
