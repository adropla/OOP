// LABA212.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm> 
#include <windows.h>
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

int main()
{
	setlocale(LC_ALL, "");
	char dump;

	do {
		int i = 0, a = 0, b = 0, c = 0, d = 0;
		double result = 0;
		char operation;
		string exp, temp;
		system("cls");
		getline(cin, exp); // ввод
		exp = removeSpaces(exp);
		exp += ' ';

		for (int j = 0; j < 4; j++) { // считывание перменных a b c d
			while (isdigit(exp[i])) { 
				temp += exp[i++];
			}
			switch (j) {
				case 0:
					a = stoi(temp);
					exp.erase(temp.length(), 1);
					i--;
					break;
				case 1:
					b = stoi(temp);
					break;
				case 2:
					c = stoi(temp);
					break;
				case 3:
					d = stoi(temp);
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
				result = (double)(a*d + b * c) / (b*d);
				break;
			case '-':
				result = (double)(a*d - b*c) / (b*d);
				break;
			case '*':
				result = (double)(a*c) / (b*d);
				break;
			case '/':
				result = (double)(a*d) / (b*c);
				break;
		}

		gotoxy(exp.length() + 1+2, 0);
		cout << " = " << result << endl;
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
