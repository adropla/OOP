// LABA28.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int f1, sh1, p1, f2, sh2, p2, f, sh, p;
	char dump;

	do {
		system("cls");
		cout << "Введите первую сумму: "; cin >> f1 >> dump >> sh1 >> dump >> p1;
		cout << "Введите вторую сумму: "; cin >> f2 >> dump >> sh2 >> dump >> p2;

		p = (p1 + p2) % 12;
		sh = (sh1 + sh2 + (p1+p2) / 12) % 20;
		f = f1 + f2 + (sh1 + sh2 + (p1 + p2) / 12) / 20;

		cout << "Всего: " << f << " " << sh << " " << p << endl;

		cout << "Продолжить?(y/n) "; cin >> dump;
	} while (dump == 'y');
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
