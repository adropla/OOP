#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

enum etype { laborer, secretary, manager, accountant, executive, researcher } e; 

string getTextForEnum(int enumVal)
{
	switch (enumVal)
	{
		case laborer:
			return "laborer";
		case secretary:
			return "secretary";
		case manager:
			return "manager";
		case accountant:
			return "accountant";
		case executive:
			return "executive";
		case researcher:
			return "researcher";

		default:
			return "Not recognized..";
	}
}

int main()
{
	setlocale(0, "");
	char dump;
	cout << "Введите первую букву должности" << endl
		 << "(laborer, secretary, manager, accountant, executive, researcher) : ";
	cin >> dump;
	cout << "Полное название должности: ";
	switch (dump) {
		case 'l':
			cout << getTextForEnum(laborer);
			break;
		case 's':
			cout << getTextForEnum(secretary);
			break;
		case 'm':
			cout << getTextForEnum(manager);
			break;
		case 'a':
			cout << getTextForEnum(accountant);
			break;
		case 'e':
			cout << getTextForEnum(executive);
			break;
		case 'r':
			cout << getTextForEnum(researcher);
			break;
	}
}