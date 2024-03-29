// DEFENCE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char dump;
	do {
		system("cls");
		int day1, month1, year1, days1 = 0,
			day2, month2, year2, days2 = 0,
			i;
		cout << "Format dd.mm.yyyy" << endl;
		cin >> day1 >> dump >> month1 >> dump >> year1;
		cin >> day2 >> dump >> month2 >> dump >> year2;

		for (i = 0; i < year1; i++) {
			if (i % 4 == 0) days1 += 366;
			else days1 += 365;
		}
		for (i = 0; i < month1; i++) {
			switch (i) {
				case 1:
					days1 += 31;
					break;
				case 2:
					if (i % 4 == 0) days1 += 29;
					else days1 += 28;
					break;
				case 3:
					days1 += 31;
					break;
				case 4:
					days1 += 30;
					break;
				case 5:
					days1 += 31;
					break;
				case 6:
					days1 += 30;
					break;
				case 7:
					days1 += 31;
					break;
				case 8:
					days1 += 31;
					break;
				case 9:
					days1 += 30;
					break;
				case 10:
					days1 += 31;
					break;
				case 11:
					days1 += 30;
					break;
				case 12:
					days1 += 31;
					break;
			}
		}
		days1 += day1;

		for (i = 0; i < year2; i++) {
			if (i % 4 == 0) days2 += 366;
			else days2 += 365;
		}
		for (i = 0; i < month2; i++) {
			switch (i) {
			case 1:
				days2 += 31;
				break;
			case 2:
				if (i % 4 == 0) days2 += 29;
				else days2 += 28;
				break;
			case 3:
				days2 += 31;
				break;
			case 4:
				days2 += 30;
				break;
			case 5:
				days2 += 31;
				break;
			case 6:
				days2 += 30;
				break;
			case 7:
				days2 += 31;
				break;
			case 8:
				days2 += 31;
				break;
			case 9:
				days2 += 30;
				break;
			case 10:
				days2 += 31;
				break;
			case 11:
				days2 += 30;
				break;
			case 12:
				days2 += 31;
				break;
			}
		}
		days2 += day2;

		cout << days2 - days1 << " дней" << endl;
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
