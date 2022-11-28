#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <typeinfo>
#include <iomanip>
using namespace std;

int CheckInt(int n) {
	int temp = 0;
	while (1) {
		cin >> temp;
		if (!cin || temp <= 0 || temp > n) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "\n\tYou need to enter a numeric positive value less than " << n << "\n\t\t";
		}
		else {
			cin.ignore(32767, '\n');
			return temp;
		}
	}
}