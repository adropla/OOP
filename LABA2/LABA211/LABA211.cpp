// LABA211.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 
#include <windows.h>
using std::cin;
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

	do { // цикл вычисления
		int i = 0, f = 0, sh = 0, p = 0, k = 0, tP = 0, tSh = 0;
		bool flag = 0;
		char operation;
		string exp, temp;
		system("cls");
		cout << "Формат ввода $x.x.x, x - цифра" << endl;
		getline(cin, exp); // ввод
		exp = removeSpaces(exp); 
		exp += ' ';
		if (exp.find("$") == string::npos) break;
		
		if (exp.find("+") != string::npos) operation = '+'; // распознавание операции
		if (exp.find('-') != string::npos) operation = '-';
		if (exp.find('*') != string::npos) operation = '*';
		if (exp.find('/') != string::npos) operation = '/';
		
		while (exp[i] != ' ') {  // цикл считывания выражения
			if (exp[i] == '$') {
				while (exp[++i] != '.') { // считывание фунтов
					temp += exp[i];
				}
				switch (operation) {
					case '+':
						f += stoi(temp);
						break;
					case '*':
					case '/':
					case '-':
						if (!flag) {
							f = stoi(temp);
							break;
						}
						f -= stoi(temp);
						break;
				}
				temp = "";

				while (exp[++i] != '.') { // считывание шилингов 
					temp += exp[i];
				}
				switch (operation) {
					case '+':
						sh += stoi(temp);
						break;
					case '*':
					case '/':
					case '-':
						if (!flag) {
							sh = stoi(temp);
							break;
						}
						sh -= stoi(temp);
						break;
				}
				temp = "";

				while (isdigit(exp[++i])) { // считывание пенсов
					temp += exp[i];
				}
				switch (operation) {
				case '+':
					p += stoi(temp);
					break;
				case '*':
				case '/':
				case '-':
					if (!flag) {
						p = stoi(temp);
						break;
					}
					p -= stoi(temp);
					break;
				}
				temp = "";

				flag = 1; // индикатор второй суммы
			}
			if (exp[i] == operation) i++;

			while (exp[i] != ' ') { // считывание коэфициента при * и /
				temp += exp[i++];
			}
			k = stoi(temp);
			switch (operation) { 
				case '*':
					tP = p;
					p = (p*k) % 12;
					tSh = sh;
					sh = ((sh*k) + (tP*k) / 12) % 20;
					f = (f*k) + (((tSh*k) + (tP*k) / 12) / 20);
					break;
				case '/':
					tP = ((f * 20 + sh) * 12 + p) / k;
					f = tP /(12 * 20);
					tP = tP - f*12*20;
					sh = tP/12;
					p = tP - sh*12;
					break;
			}
		}
		gotoxy(exp.length()+1, 0);
		cout << " = $" << f << "." << sh << "." << p << endl;
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
