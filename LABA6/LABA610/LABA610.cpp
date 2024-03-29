// LABA610.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class matrix {
private:
	int** mat;
public:
	//конструкторы
	matrix(int a, int b) {
		str = a; col = b;
		mat = new int*[str];
		for (int i = 0; i < col; ++i) mat[i] = new int[col];
	};
	matrix() : matrix(0, 0) {};

	//статические переменные
	static int str,
			   col;

	//методы
	void putEl(int indexString, int indexCollum, int element) {
		if ((indexString < 0) || (indexString > str - 1) || (indexCollum < 0) || (indexCollum > col - 1)) {
			cout << "Выход за границы матрицы";
			exit(1);
		}
		else mat[indexString][indexCollum] = element;
	};
	int getEl(int indexString, int indexCollum) {
		if ((indexString < 0) || (indexString > str - 1) || (indexCollum < 0) || (indexCollum > col - 1)) {
			cout << "Выход за границы матрицы";
			exit(1);
		}
		else return mat[indexString][indexCollum];
	}
};

int matrix::str = 0,
    matrix::col = 0;

int main()
{
	setlocale(0, "");
	matrix a(10, 10);
	int temp = 123456;
	a.putEl(1, 1, temp);
	cout << a.getEl(1, 1);
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
