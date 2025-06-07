#include <iostream>
using namespace std;

class CA {
public:
	virtual void met1() {
		cout << "metoda1 virtual CA\n";
	}
	void met2() {
		cout << "metoda2 CA\n";
	}
	void met3() {
		cout << "metoda3 CA\n";
		met1();
		met2();
	}
};

class CB : public CA {
public:
	void met1() {
		cout << "metoda1 CB\n";
	}
	void met2() {
		cout << "metoda2 CB\n";
	}
};

int main() {
	CA a;
	CB b;

	a.met1();
	a.met2();
	cout << "======\n";
	b.met1();
	b.met2();
	cout << "======\n";
	a.met3();
	b.met3();
}