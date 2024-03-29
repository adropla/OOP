// LABA510.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	void getGeoPosition() {
		char dump;
		cin >> degree >> dump >> minute >> dump >> direction;
		if (cin.fail()) {
			cout << "Ошибка! Неправильнный ввод" << endl;
			cin.clear();
			cin.ignore(255, '\n');
			exit(0);
		}
	};
	void displayGeoPosition()const {
		cout << degree << '\xB0' << minute << "' " << direction << " ";
	};
};

class ship {
private:
	int id;
	geoPosition longtitude;
	geoPosition latitude;
public:
	static int counter;
	ship() { id = counter++; longtitude.getGeoPosition(); latitude.getGeoPosition(); };
	void displayShip() {
		cout << "Корабль с номером " << id << " находится в точке "; 
		longtitude.displayGeoPosition();  latitude.displayGeoPosition();
	}
};

int ship::counter = 0;

int main()
{
	setlocale(0, "");
	cout << "Геопозиция первого корабля: " << endl; ship s1;
	cout << "Геопозиция второго корабля: " << endl; ship s2;
	cout << "Геопозиция третьего корабля: " << endl; ship s3;

	s1.displayShip(); cout << endl;
	s2.displayShip(); cout << endl;
	s3.displayShip();
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
