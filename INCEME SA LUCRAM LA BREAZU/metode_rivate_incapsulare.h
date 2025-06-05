#pragma once
class Calculator {
private:
    int verificaDate(int x) {
        return (x >= 0) ? x : 0;
    }

public:
    int patratPozitiv(int x) {
        x = verificaDate(x);
        return x * x;
    }
};
