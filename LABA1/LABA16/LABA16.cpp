#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(0, "");
	double i;
	cout << "Enter $: ";
	cin >> i;
	
	cout << i / 1.487 << " фунтов стерлингов\n";
	cout << i / 0.172 << " франков\n";
	cout << i / 0.584 << " немецких марок\n";
	cout << i / 0.00955 << " японских йен\n";
	getchar();
}