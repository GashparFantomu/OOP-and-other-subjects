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
//instanta incuibarita - Masina are un motor - relatie de tip "are un"
//Mostenirea - o decapotabila (Cabriolet) este o masina - relatie de tip "este un"