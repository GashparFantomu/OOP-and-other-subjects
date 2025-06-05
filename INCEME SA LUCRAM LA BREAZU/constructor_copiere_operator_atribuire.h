#pragma once
#include <iostream>

using namespace std;

class CA {
public:
	int x;
	CA(int x) {
		this->x = x;
		cout << "constructor int " << x << endl;
	}
	CA(const CA& other) { //constructor copiere,  se pune referinta ca sa nu apeleze constructorul pentru obiectul din parametru
		this->x = other.x; //x-ul noului obiect
		cout << "constructor copiere: " << x << endl;
	}
	CA& operator=(const CA& other) {//operator atribuire
		this->x = other.x;
		cout << "operator= : " << x << endl;
		return *this; //returneaza referinta obiectului curent, ca sa poti face atribuire in lant a = b = c
	}
};

//CA function_by_value(CA c) {
//	cout << "function_by_value, c.x = " << c.x << " copiat" << endl;
//	return c;
//}

int main() {
	CA a(10); //constructor int
	CA b = a; //constructor copiere
	CA c(5);
	a = c; //operator atribuire

}