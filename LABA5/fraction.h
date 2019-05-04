#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

class fraction {
public:
	int num;
	int den;

	fraction(int a, int b) { num = a; den = b; };
	fraction() : fraction(0, 0) { num = 0, den = 0; };

	void setFraction() {
		char dump;
		cin >> num >> dump >> den;
		if (cin.fail()) {
			cout << "Ошибка! Неправильнный ввод" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			exit(0);
		}
	};

	string displayFraction() {
		return to_string(num) + "/" + to_string(den);
	};

	static fraction addFraction(fraction a, fraction b) {
		fraction result;
		result.num = a.num*b.den + b.num*a.den;
		result.den = a.den*b.den;
		return result;
	};

	static fraction subFraction(fraction a, fraction b) {
		fraction result;
		result.num = a.num*b.den - b.num*a.den;
		result.den = a.den*b.den;
		return result;
	};

	static fraction mulFraction(fraction a, fraction b) {
		fraction result;
		result.num = a.num*b.num;
		result.den = a.den*b.den;
		return result;
	};

	static fraction divFraction(fraction a, fraction b) {
		fraction result;
		result.num = a.num*b.den;
		result.den = a.den*b.num;
		return result;
	};

	static fraction fractionSimplification(fraction a) {
		fraction fResult;
		long tnum, tden, temp, gcd;
		tnum = labs(a.num); // Используем неотрицательные значения
		tden = labs(a.den); // Нужен cmath
		if (tden == 0) { // Проверка знаменателя 
			cout << "Недопустимый знаменатель"; exit(1);
		}
		else if (tnum == 0) {
			fResult.num = 0;
			fResult.den = 1;
			return fResult;
		}
		// Нахождение наибольшего общего делителя 
		while (tnum != 0) {
			if (tnum < tden) { // Если числитель больше знаменателя, меняем их местами.
				temp = tnum;
				tnum = tden;
				tden = temp;
			}
			tnum = tnum - tden;
		}
		gcd = tden;// Делим числитель и знаменатель на НОД.
		fResult.num = a.num / gcd;
		fResult.den = a.den / gcd;
		return fResult;
	};
};