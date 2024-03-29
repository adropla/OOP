#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm> 
#include <windows.h>
using namespace std;

struct fraction {
	int num;
	int den;
};

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

fraction fadd(fraction a, fraction b) {
	fraction fRes;
	fRes.num = a.num * b.den + a.den * b.num;
	fRes.den = a.den * b.den;
	return fRes;
}

fraction fsub(fraction a, fraction b) {
	fraction fRes;
	fRes.num = a.num * b.den - a.den * b.num;
	fRes.den = a.den * b.den;
	return fRes;
}

fraction fmul(fraction a, fraction b) {
	fraction fRes;
	fRes.num = a.num * b.num;
	fRes.den = a.den * b.den;
	return fRes;
}

fraction fdiv(fraction a, fraction b) {
	fraction fRes;
	fRes.num = a.num * b.den;
	fRes.den = a.den * b.num;
	return fRes;
}

int main()
{
	setlocale(LC_ALL, "");
	char dump;

	do {
		int i = 0, expLen = 0;// f1.num - a | f1.den - b | f2.num - c | f2.den - d
		fraction f1, f2, fResult;
		double dResult = 0;
		char operation;
		string exp, temp;
		system("cls");
		getline(cin, exp); // ввод
		expLen = exp.length();
		exp = removeSpaces(exp);
		exp += ' ';

		for (int j = 0; j < 4; j++) { // считывание перменных a b c d
			while (isdigit(exp[i])) {
				temp += exp[i++];
			}
			switch (j) {
			case 0:
				f1.num = stoi(temp);
				exp.erase(temp.length(), 1);
				i--;
				break;
			case 1:
				f1.den = stoi(temp);
				break;
			case 2:
				f2.num = stoi(temp);
				break;
			case 3:
				f2.den = stoi(temp);
				exp.erase(exp.length() - temp.length() - 2, 1);
				break;
			}
			temp = ""; i++;
		}

		if (exp.find("+") != string::npos) operation = '+'; // распознавание операции
		if (exp.find('-') != string::npos) operation = '-';
		if (exp.find('*') != string::npos) operation = '*';
		if (exp.find('/') != string::npos) operation = '/';

		switch (operation) {
			case '+':
				fResult = fadd(f1, f2);
				break;
			case '-':
				fResult = fsub(f1, f2);
				break;
			case '*':
				fResult = fmul(f1, f2);
				break;
			case '/':
				fResult = fdiv(f1, f2);
				break;
		}
		dResult = double(fResult.num) / double(fResult.den);

		gotoxy(expLen, 0);
		if (fResult.num == 0) cout << " = " << fResult.num << endl;
		else cout << " = " << fResult.num << "/" << fResult.den << " или " << dResult << endl;
		cout << "Продолжить?(y/n) "; cin >> dump;
		cin.ignore();
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


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
