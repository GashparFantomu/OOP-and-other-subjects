#pragma once
#include <iostream>
using namespace std;
class Singleton {
	static Singleton* instance;
	Singleton() {}
public:
	static Singleton* getInstance();
	int membru = 0;
};

Singleton* Singleton::instance = NULL;

Singleton* Singleton::getInstance() {

	if (instance == NULL) {

		instance = new Singleton();
	}
	// intoarce instanta existenta
	return instance;
}

int main()
{
	Singleton* obiect1 = Singleton::getInstance();
	obiect1->membru = 100;

	cout << "membru obiect1 = " << obiect1->membru << endl;
	cout << "adresa obiect1 = " << obiect1 << endl;
}