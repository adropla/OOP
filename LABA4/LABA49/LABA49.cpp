// LABA48.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

struct time {
	int hours;
	int minutes;
	int seconds;
};

void swap(time *a, time *b) {
	time *t;
	t = a;
	a = b;
	b = t;
}

int main()
{
	setlocale(0, "");
	time t1, t2;
	char dump;
	cin >> t1.hours >> dump >> t1.minutes >> dump >> t1.seconds;
	cin >> t2.hours >> dump >> t2.minutes >> dump >> t2.seconds;
	swap(t1, t2);
	cout << endl << t1.hours << ":" << t1.minutes << ":" << t1.seconds << endl
		<< t2.hours << ":" << t2.minutes << ":" << t2.seconds;

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
