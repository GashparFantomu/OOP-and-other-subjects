#pragma once
#include <iostream>
using namespace std;
class Motor {
public:
    void porneste() { cout << "Motor pornit\n"; }
};

class Masina {
    Motor motor; //instanta incuibarita
public:
    void ruleaza() {
        motor.porneste();
        cout << "Masina se misca\n";
    }
};
//nu iti mai trebe mostenire