#include "pch.h"
#include <iostream>
#include <cstdlib>         
#include <ctime>           
#include <io.h>
#include <fcntl.h>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card
{
private:
	int number;        
	Suit suit;        
public:
	card() { };
	void set(int n, Suit s);
	void display();
};

void card::set(int n, Suit s) {
	suit = s; number = n;
};

void card::display()            
{
	if (number >= 2 && number <= 10)
		wcout << number;
	else
		switch (number)
		{
		case jack:  wcout << "J"; break;
		case queen: wcout << "Q"; break;
		case king:  wcout << "K"; break;
		case ace:   wcout << "A"; break;
		}
	switch (suit)
	{
	case clubs:    wprintf(L"\x2663"); break;
	case diamonds: wprintf(L"\x2666"); break;
	case hearts:   wprintf(L"\x2665"); break;
	case spades:   wprintf(L"\x2660"); break;
	}
}

int main()
{
	_setmode(_fileno(stdout), _O_WTEXT);
	card deck[52];
	int j;
	//заполнение колоды
	for (j = 0; j < 52; j++)        
	{
		int num = (j % 13) + 2;  
		Suit su = Suit(j / 13);  
		deck[j].set(num, su);  
	}
	//вывод сортированной колоды
	wcout << "\nOrdered deck:\n";
	for (j = 0; j < 52; j++)       
	{
		deck[j].display();
		wcout << "  ";
		if (!((j + 1) % 13))   
			wcout << endl;
	}
	//случайное перемешивание и разбиение на 4 подколоды
	srand(time(NULL));       
	for (j = 0; j < 52; j++)        
	{
		int k = rand() % 52;    
		card temp = deck[j];   
		deck[j] = deck[k];
		deck[k] = temp;
	}
	//вывод перемешанной колоды
	wcout << "\nShuffled deck:\n";
	for (j = 0; j < 52; j++)      
	{
		deck[j].display();
		wcout << ", ";
		if (!((j + 1) % 13))   
			wcout << endl;
	}
}