#pragma once
#include <iostream>
#include <fstream>
using namespace std;


int main() {
	int age;

	try {
		cout << "insert age; ";
		cin >> age;
		if (age <= 12) {
			throw age;
		}
	}
	catch (int ageError) {
		cout << "go to prison you pedo\nwho the fuck is " << ageError << " in the 12th grade? see you in court!\n";
	}
	catch (...) {
		cout << "i catch you without reason, well.. not if they catch you first";
	}
}