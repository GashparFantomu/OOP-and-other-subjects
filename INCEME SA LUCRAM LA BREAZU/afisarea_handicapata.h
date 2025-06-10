#pragma once
#include <iostream>
#include <string>

class C {
public:
    int x = 0;
    std::string y;
};

int main() {
    C c;
    c.x = 3;
    c.y = "abc";

    (std::cout << std::endl << c.x) << 2 << c.y << "<<" << (c.x << 2) << c.y; //c.x << 2 - shiftare 

    return 0;
}
