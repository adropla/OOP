// LABA57.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class geoPosition {
private:
	int degree;
	float minute;
	char direction;
public:
	geoPosition(int deg, float m, char dir) { degree = deg; minute = m; direction = dir; };
	geoPosition() : geoPosition(0, 0, 0) { };
	void getgeoPosition() {
		char dump;
		cin >> degree >> dump >> minute >> dump >> direction;
	};
	void displaygeoPosition()const {
		cout << degree << '\xB0' << minute << "' " << direction;
	};
};

int main()
{
	setlocale(0, "");
	const geoPosition a = geoPosition(148, 82.2, 'E');
	geoPosition b = geoPosition();
	char dump;
	a.displaygeoPosition();
	getchar();
	do {

		dump = 0;
		system("cls");
		b.getgeoPosition();
		if (cin.fail())
		{
			cout << "Error!";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else b.displaygeoPosition();
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
