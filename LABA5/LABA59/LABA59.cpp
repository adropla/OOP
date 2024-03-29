// LABA59.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

class fraction {
private:
	int num;
	int den;
public:
	fraction() { num = 0, den = 0; };
	void getFraction() {
		char dump;
		cin >> num >> dump >> den;
		if (cin.fail()) {
			cout << "Error!" << endl;
			cin.clear();
			cin.ignore(255, '\n');
		}
	};
	void displayFraction() {
		cout << num << "/" << den;
	};
	static fraction addFraction(fraction a, fraction b) {
		fraction result;
		result.num = a.num*b.den + b.num*a.den;
		result.den = a.den*b.den;
		return result;
	};
};

int main()
{
	setlocale(0, "");
	char dump;
	fraction f1, f2;

	do {
		system("cls");
		f1.getFraction();
		f2.getFraction();
		fraction::addFraction(f1, f2).displayFraction();
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
