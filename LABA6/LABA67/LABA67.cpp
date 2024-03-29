// LABA67.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include "../../LABA5/fraction.h"
using namespace std;

class money {
private:
	long double value;
public:
	void mstold(string str);
	long double getValue();
};

long double money::getValue() {
	return value;
}

void money::mstold(string str) {
	string buf = removeSpaces(str),
		   result;
	buf += ' ';

	for (int i = 0; i < buf.size(); i++){
		if ((buf[i] == '.') && (i == buf.find_last_of('.'))) {// Добавляется все цифры после точки
			int j = i;
			result += ".";
			while (buf[j++] != ' ') {
				if (isdigit(buf[j])) result += buf[j];
			}
			break;
		}
		else if (isdigit(buf[i])) result += buf[i]; // добавляет только цифры
	}
	
	const char *c = result.c_str();
	value = strtold(c, NULL);
}

int main()
{
	money temp;
	string buffer;
	getline(cin, buffer);
	temp.mstold(buffer);
	cout << fixed << temp.getValue();
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
