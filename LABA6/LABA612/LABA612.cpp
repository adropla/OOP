// LABA612.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "../../LABA5/fraction.h"
using namespace std;

class bMoney {
private:
	long double value;
public:
	bMoney(string s) { value = mstold(s); };
	bMoney(long double ld) { value = ld; };
	bMoney() : bMoney(0) { };
	
	static bMoney mAdd(bMoney m1, bMoney m2);
	void setValue();
	void setValue(long double ld);
	void setValue(string s);
	long double getValue();
	void printValue();
	long double mstold(string str);
	string ldtoms(long double num);
};

string bMoney::ldtoms(long double num) {
	if (num > 9999999999999999) {
		cout << "Неправильный ввод"; return 0;
	}

	string temp = " " + to_string(num);
	string result = temp.substr(temp.find_last_of('.'), string::npos); // Запись в строку всю дробную часть
	int i = temp.length() - result.length() - 1;
	int k = 1;

	while (temp[i] != ' ') {
		result = temp[i] + result;
		if (k % 3 == 0) result = " " + result;
		i--; k++;
	}

	return "$" + result;
}

bMoney mAdd(bMoney m1, bMoney m2) {
	bMoney result;
	result.setValue((long double)(m1.getValue() + m2.getValue()));
	return result;
}

void bMoney::setValue(long double ld) {
	value = ld;
}

void bMoney::setValue(string s) {
	value = mstold(s);
}

void bMoney::setValue() {
	string s;
	getline(cin, s);
	value = mstold(s);
}

long double bMoney::getValue() {
	return value;
}

void bMoney::printValue(){
	cout << ldtoms(value);
}

long double bMoney::mstold(string str) {
	string buf = removeSpaces(str),
		result;
	buf += ' ';

	for (int i = 0; i < buf.size(); i++) {
		if ((buf[i] == '.') && (i == buf.find_last_of('.'))) {// Добавляется все цифры после точки
			int j = i;
			result += ".";
			while (buf[j++] != ' ') {
				if (isdigit(buf[j])) result += buf[j];
			}
			break;
		}
		else if (isdigit(buf[i])) result += buf[i]; // добавляет только цифры
	}

	const char *c = result.c_str();
	return strtold(c, NULL);
}

int main()
{
	char dump;
	bMoney a, b;

	do {
		system("cls");
		a.setValue();
		b.setValue();
		mAdd(a, b).printValue();
		cout << endl << "Continue?(y/n) "; cin >> dump;
		cin.ignore(255, '\n');
		cin.clear();
	} while (dump != 'n');
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
