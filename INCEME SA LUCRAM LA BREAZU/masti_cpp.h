#pragma once
#include <iostream>
using namespace std;

int main() {
    unsigned char flags = 0; // 00000000

    // Setăm bitul 2 (pornim un „flag”)
    flags |= (1 << 2); // 00000100
    cout << "Dupa setare: " << (int)flags << endl;

    // Testăm bitul 2
    if (flags & (1 << 2))
        cout << "Bitul 2 este setat.\n";

    // Resetăm bitul 2
    flags &= ~(1 << 2); // 00000000
    cout << "Dupa resetare: " << (int)flags << endl;

    // Comutăm bitul 0
    flags ^= (1 << 0); // 00000001
    cout << "Dupa comutare: " << (int)flags << endl;
}
