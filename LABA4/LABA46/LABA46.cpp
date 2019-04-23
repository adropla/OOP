// LABA46.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
using namespace std;

char dump;

struct time {
	int hours;
	int minutes;
	int seconds;
};

long time_to_secs(time t) {
	long totalsecs = t.hours * 3600 + t.minutes * 60 + t.seconds;
	return totalsecs;
}

time secs_to_time(long secs) {
	time tResult;
	tResult.hours = secs / 3600;
	tResult.minutes = (secs % 3600) / 60;
	tResult.seconds = (secs % 3600) % 60;
	return tResult;
}

int main()
{
	setlocale(0, "");
	time t1, t2, tSum;
	cin >> t1.hours >> dump >> t1.minutes >> dump >> t1.seconds;
	cin >> t2.hours >> dump >> t2.minutes >> dump >> t2.seconds;
	tSum = secs_to_time(time_to_secs(t1)+time_to_secs(t2));
	cout << tSum.hours << ":" << tSum.minutes << ":" << tSum.seconds;
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
