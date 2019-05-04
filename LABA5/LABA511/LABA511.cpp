// LABA511.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "../fraction.h"

int main()
{
	setlocale(LC_ALL, "");
	char dump;

	do {
		int i = 0, expLen = 0;// f1.num - a | f1.den - b | f2.num - c | f2.den - d
		fraction f1, f2, fResult;
		double dResult = 0;
		char operation;
		string exp, temp;
		system("cls");
		getline(cin, exp); // ввод
		expLen = exp.length();
		exp = removeSpaces(exp);
		exp += ' ';

		for (int j = 0; j < 4; j++) { // считывание выражения
			while (isdigit(exp[i])) { //считывание дроби
				temp += exp[i++];
			}
			if (temp.length() == 0) { // проверка на 
				cout << "Ошибка! Неправильнный ввод" << endl;
				exit(0);
			}
			switch (j) {
			case 0:
				f1.num = stoi(temp);
				exp.erase(temp.length(), 1);
				i--;
				break;
			case 1:
				f1.den = stoi(temp);
				break;
			case 2:
				f2.num = stoi(temp);
				break;
			case 3:
				f2.den = stoi(temp);
				exp.erase(exp.length() - temp.length() - 2, 1);
				break;
			}
			temp = ""; i++;
		}

		if (exp.find("+") != string::npos) operation = '+'; // распознавание операции
		if (exp.find('-') != string::npos) operation = '-';
		if (exp.find('*') != string::npos) operation = '*';
		if (exp.find('/') != string::npos) operation = '/';

		switch (operation) {
		case '+':
			fResult = fraction::addFraction(f1, f2);
			break;
		case '-':
			fResult = fraction::subFraction(f1, f2);
			break;
		case '*':
			fResult = fraction::mulFraction(f1, f2);
			break;
		case '/':
			fResult = fraction::divFraction(f1, f2);
			break;
		}
		dResult = double(fResult.num) / double(fResult.den);
		fResult = fraction::fractionSimplification(fResult);

		gotoxy(expLen, 0);
		if (fResult.num == 0) cout << " = " << fResult.num << endl;
		else cout << " = " << fResult.displayFraction() << " или " << dResult << endl;
		cout << "Продолжить?(y/n) "; cin >> dump;
		cin.ignore();
	} while (dump != 'n');
}