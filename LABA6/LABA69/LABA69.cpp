#include "pch.h"
#include <iostream>
using namespace std;

class Queue {
private:
	enum { MAX = 10 };
	int st[MAX];
	int head;
	int tail;
public:
	Queue() { head = 0; tail = -1; };
	void put(int var);
	int get();
};

int Queue::get() {
	if (head == MAX) { head = 0; }
	int output = st[head++];
	return output;
}

void Queue::put(int var) {
	if (tail == MAX - 1) { tail = -1; }
	st[++tail] = var;
}

int main()
{
	Queue s1;

	s1.put(11);
	s1.put(22);
	cout << "1: " << s1.get() << endl;  //11
	cout << "2: " << s1.get() << endl;  //22
	s1.put(33);
	s1.put(44);
	s1.put(55);
	s1.put(66);
	cout << "3: " << s1.get() << endl;  //33
	cout << "4: " << s1.get() << endl;  //44
	cout << "5: " << s1.get() << endl;  //55
	cout << "6: " << s1.get() << endl;  //66
}