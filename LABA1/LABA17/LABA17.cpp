#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(0, "");
	double i;
	cout << "Enter °C: ";
	cin >> i;
	cout << i*9/5 + 32 << " °F\n";
	getchar();
}