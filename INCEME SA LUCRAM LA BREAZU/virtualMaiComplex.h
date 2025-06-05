#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Instrument {
public:
    Instrument() { cout << "[Instrument] constructor\n"; }
    virtual ~Instrument() { cout << "[Instrument] destructor\n"; }

    // Metodă virtuală: apel dinamic
    virtual void play() const {
        cout << "Instrument face un sunet generic\n";
    }

    // Metodă non-virtuală: legare statică
    void tune() const {
        cout << "Instrument este acordat în mod generic\n";
    }
};

class Piano : public Instrument {
public:
    Piano() { cout << "[Piano] constructor\n"; }
    ~Piano() override { cout << "[Piano] destructor\n"; }

    // Suprascriem metoda virtuală
    void play() const override {
        cout << "Piano: *plimbe degetele pe clape* 🎹\n";
    }

    // Supradefinim tune() dar nu îl facem virtual
    void tune() const {
        cout << "Piano este acordat cu acordor de pian\n";
    }
};

class Guitar : public Instrument {
public:
    Guitar() { cout << "[Guitar] constructor\n"; }
    ~Guitar() override { cout << "[Guitar] destructor\n"; }

    void play() const override {
        cout << "Guitar: *ciupeşte corzile* 🎸\n";
    }
    // Nu suprascriem tune(), vom moşteni Instrument::tune()
};

// O clasă care nu are play() virtuală
class Drum : public Instrument {
public:
    Drum() { cout << "[Drum] constructor\n"; }
    ~Drum() override { cout << "[Drum] destructor\n"; }

    // Redefinim play, dar fără override
    void play() const {
        cout << "Drum: *loveşte pielea* 🥁\n";
    }
};

int main() {
    cout << "=== Creare obiecte în vector de Instrument* ===\n";
    vector<Instrument*> orchestra;
    orchestra.push_back(new Piano());
    orchestra.push_back(new Guitar());
    orchestra.push_back(new Drum());
    orchestra.push_back(new Instrument());

    cout << "\n=== Apeluri polimorfice prin Instrument* ===\n";
    for (auto inst : orchestra) {
        inst->play();    // virtual → dinamic
        inst->tune();    // non-virtual → static, apel Instrument::tune
        cout << "---\n";
    }

    cout << "\n=== Exemplu object slicing ===\n";
    Instrument sliced = *orchestra[0];  // se taie partea derivată
    sliced.play();  // va apela Instrument::play()
    sliced.tune();  // Instrument::tune()

    cout << "\n=== Downcasting safe cu dynamic_cast ===\n";
    Instrument* bla = orchestra[1]; // tip real: Guitar
    if (Guitar* g = dynamic_cast<Guitar*>(bla)) {
        cout << "Am downcast-uit la Guitar cu succes!\n";
        g->play();
    }
    else {
        cout << "Downcast eșuat!\n";
    }

    cout << "\n=== Eliberare memorie (destructori în ordine inversă) ===\n";
    for (auto inst : orchestra) {
        delete inst;
    }
    return 0;
}
