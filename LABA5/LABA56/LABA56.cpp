// LABA56.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

class date {
private:
	int month;
	int day;
	int year;
public:
	date(int m, int d, int y) { month = m; day = d; year = y; };
	date() : date(0, 0, 0) { };
	void getdate() {
		char dump;
		cin >> month >> dump >> day >> dump >> year;
	};
	string showdate() {
		return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
	};
};

class employee {
private:
	int id;
	float salary;
	date acceptionDate;
	string post;
public:
	employee(int i, float s) { id = i; salary = s; }; // инициализации с аргументами
	employee() : employee(0, 0) { }; // инициализация без аргументов
	string getEmploy() {
		return "Сотрудник " + to_string(id) + " с зарплатой " + to_string((int)salary) + " был принят на должность " + post + " " + acceptionDate.showdate();
	}
	void setEmploy() {
		cout << "Сотрудник: "; cin >> id;
		cout << "Зарплата: "; cin >> salary;
		cout << "Должность: "; cin >> post;
		cout << "Дата: "; acceptionDate.getdate();
	}
};


int main()
{
	setlocale(0, "");
	employee e1, e2, e3;

	e1.setEmploy();
	system("cls");

	e2.setEmploy();
	system("cls");

	e3.setEmploy();
	system("cls");

	cout << e1.getEmploy() << endl;
	cout << e2.getEmploy() << endl;
	cout << e3.getEmploy();
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
