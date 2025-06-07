#pragma once
class Termometru {
private:
    double temperatura;

public:
    Termometru() { 
        temperatura = 0.0; 
    }

    void seteaza(double t) {
        if (t >= -273.15) // validare
            temperatura = t;
    }

    double citeste() const {
        return temperatura;
    }
};
