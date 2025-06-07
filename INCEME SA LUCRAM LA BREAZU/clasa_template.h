#pragma once
#include <iostream>
using namespace std;
template <typename T, typename U>
class A {
	T x;
	U y;
public:
	A(T x, U y) { 
		this->x = x; 
		this->y = y; 
	}
	void print() { 
		cout << x << " " << y << endl; 
	}
};
int main()
{
	A<char, char> a('A', 'B');
	A<int, double> b(1, 3.14);
	a.print();
	b.print();
	
}