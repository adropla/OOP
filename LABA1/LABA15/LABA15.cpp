#include "pch.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main()
{
	setlocale(0, "");
	char i;
	cout << "Enter char: "; 
	cin >> i;
	if (((i >= 'a') && (i <= 'z')) || ((i >= 'а') && (i <= 'я')))
		cout << true;
	else cout << false;
	getchar();
}