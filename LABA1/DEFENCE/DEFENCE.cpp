// DEFENCE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
#include <cmath>
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
	int const DtoR = 64;
	int const EtoR = 72;
	setlocale(LC_ALL, "");
	char dump;

	do {
		int x = 0;
		int i = 0;
		char choose;
		system("cls");

		cout << "Конвертировать: " << endl;
		cout << "1) рубли в доллары" << endl;
		cout << "2) рубли в евро" << endl;
		cout << "3) доллары в рубли" << endl;
		cout << "4) доллары в евро" << endl;
		cout << "5) евро в рубли" << endl;
		cout << "6) евро в доллары" << endl;
		gotoxy(16, 0);
		cin >> choose;
		gotoxy(0, 7);
		cin >> x;
		
		
		switch (choose) {
			case '1':
				cout << (double)x / DtoR;
				break;
			case '2':
				cout << (double)x / EtoR;
				break;
			case '3':
				cout << (double)x*DtoR;
				break;
			case '4':
				cout << (double)x*DtoR/EtoR;
				break;
			case '5':
				cout << (double)x*EtoR;
				break;
			case '6':
				cout << (double)x*EtoR/DtoR;
				break;
		}
		cout << endl;

		cout << "Продолжить?(y/n) "; cin >> dump;
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
