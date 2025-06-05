#pragma once
#include <iostream>

using namespace std;

class CA {
public:
    int x;

    CA() {
        x = 1;
        cout << "\nCAI " << x;
    }

    CA(int x0) {
        x = x0;
        cout << "\nCAE " << x;
    }

    CA(const CA& p) {
        x = p.x;
        cout << "\nCAC " << x;
    }

    void operator+(const CA& p) {
        x = p.x;
        cout << "\nAOP= " << x;
    }

    virtual ~CA() {
        cout << "\nDA " << x;
    }

    void met1(int r) {
        cout << "\nMTE1A " << x << " " << r;
        met2(r);
        met3(r);
    }

    virtual void met2(int r) {
        cout << "\nMET2A " << x << " " << r;
    }

    virtual void met3(int r) {
        cout << "\nMET3A " << x << " " << r;
    }
};

CA Incremeneaza(CA x, CA& y, CA z, CA& t) {
    CA r;
    cout << "\n++++";
    x.x++; y.x++; z.x++; t.x++;
    r.x = x.x + y.x + z.x + t.x;
    return r;
}

class CB : public CA {
public:
    int y;

    CB() {
        y = 2;
        cout << "\nCBI " << x << " " << y;
    }

    ~CB() override {
        cout << "\nDB " << x << " " << y;
    }

    CB(int x0, int y0 = 3) : CA(x0 + 4) {
        y = y0 + 5;
        cout << "\nCBE " << x << " " << y;
    }

    int operator+(int p) {
        cout << "\nBOP + i";
        return x + p + 1;
    }

    int operator+(const CB& p) {
        cout << "\nVOP + A";
        return x + p.x;
    }

    friend int operator+(const CB& o1, const CB& o2) {
        cout << "\nBOP + B";
        return o1.x + o2.x;
    }

    void operator=(const CB& p) {
        x = p.x;
        y = p.y;
        cout << "\nBOP= " << x << " " << y;
    }

    void met2(int r) override {
        cout << "\nMET2B " << x << " " << r;
    }

    void met3(int r) override {
        cout << "\nMET3B " << x << " " << r;
    }
};

struct CC : public CA {
    CA a;

    CC(int x0) {
        x = x0;
        cout << "\nCCE " << x << " " << a.x;
    }

    ~CC() {
        cout << "\nDC " << x << " " << a.x;
    }
};

// Obiecte globale
CA a, b(10);
CB c, * i, d(11, 12);

int main() {
    CA e(13), * f, g = d;
    CB h(14);
    CC* x;

    cout << "\nSTART";

    f = new CA(20);
    i = new CB(21, 22);

    b.met1(31);
    d.met1(32);

    cout << "\nOP " << " " << (h + d) << " " << (h.x + 2) << " " << (d + 1);

    cout << "\nXYZT " << a.x << " " << b.x << " " << e.x << " " << g.x;

    g = Incremeneaza(a, b, e, g);

    cout << "\nXYZT " << a.x << " " << b.x << " " << e.x << " " << g.x;

    delete f;
    delete i;

    d = h;
    cout << "\nd=h " << d.x << " " << d.y << " " << e.x << " " << d.y << " " << h.x << " " << h.y;

    cout << "\n" << c.x << 2 << c.y << "<<" << (c.x << 2) << c.y;

    x = new CC(22);
    delete x;

    cout << "\nSTOP\n";

    return 0;
}
