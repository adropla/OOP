// LABA411.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct sterlings {
	int pounds;
	int shilings;
	int pence;
};

sterlings input() {
	sterlings s;
	char dump;
	cin >> s.pounds >> dump >> s.shilings >> dump >> s.pence;
	return s;
}

void output(sterlings s) {
	cout << s.pounds << "." << s.shilings << "." << s.pence;
}

sterlings sum(sterlings a, sterlings b) {
	sterlings s;	
	s.pence = (a.pence + b.pence) % 12;
	s.shilings = (a.pence + b.pence) / 12 + (a.shilings + b.shilings) % 20;
	s.pounds = a.pounds + b.pounds + (a.shilings + b.shilings) / 20;
	return s;
}

int main()
{
	setlocale(0, "");
	output(sum(input(), input()));
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
