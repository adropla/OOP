#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "");
	cout << 1990 << setfill('.') << setw(8) << 135 << endl
		<< 1991 << setw(8) << 7290 << endl
		<< 1992 << setw(8) << 11300 << endl
		<< 1993 << setw(8) << 16200 << endl;
	getchar();
}