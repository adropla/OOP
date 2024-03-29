// LABA47.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

double power(double n, int p = 2)
{
	double result = 1.0;//начать с 1
	for (int j = 0; j < p; j++)//умножить на n
		result *= n;//p раз
	return result;
}

double power(float n, int p = 2)
{
	double result = 1.0;//начать с 1
	for (int j = 0; j < p; j++)//умножить на n
		result *= n;//p раз
	return result;
}

double power(int n, int p = 2)
{
	double result = 1.0;//начать с 1
	for (int j = 0; j < p; j++)//умножить на n
		result *= n;//p раз
	return result;
}

double power(long n, int p = 2)
{
	double result = 1.0;//начать с 1
	for (int j = 0; j < p; j++)//умножить на n
		result *= n;//p раз
	return result;
}

double power(char n, int p = 2)
{
	double result = 1.0;//начать с 1
	for (int j = 0; j < p; j++)//умножить на n
		result *= n;//p раз
	return result;
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

int main()
{
	setlocale(0, "");
	int dump, numInt, pow;
	float numFloat;
	double numDouble;
	char numChar;
	long numLong;

	cout << "Номер: " << endl
		<< "1) Power Double" << endl
		<< "2) Power Float" << endl
		<< "3) Power Int" << endl
		<< "4) Power Long" << endl
		<< "5) Power Char";
	gotoxy(7, 0);
	cin >> dump;

	system("cls");
	gotoxy(0, 0);

	switch (dump) {
		case 1:
			cin >> numDouble >> pow;
			cout << power(numDouble, pow);
			break;
		case 2:
			cin >> numFloat >> pow;
			cout << power(numFloat, pow);
			break;
		case 3:
			cin >> numInt >> pow;
			cout << power(numInt, pow);
			break;
		case 4:
			cin >> numLong >> pow;
			cout << power(numLong, pow);
			break;
		case 5:
			cin >> numChar >> pow;
			cout << power(numChar, pow);
			break;
	}

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
