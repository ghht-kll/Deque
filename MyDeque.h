#pragma once
#include <iostream>

struct Element
{
	int value;
	Element* nextElement;
	Element* previousElement;
};

class MyDeque
{
private:
	Element* firstElement;
	Element* lastElement;
	unsigned int sizeDeque;
	bool checkSize(unsigned int);
	void set_front(unsigned int, double);
	int get_front(unsigned int);
public:	
	MyDeque();
	MyDeque(MyDeque*);
	void push_back(double);
	void push_front(double);
	int pop_back();
	int pop_front();
	int back();
	int front();
	void clear();
	void clear_back(unsigned int);
	void clear_front(unsigned int);
	void sort();
	unsigned int getSize();
	~MyDeque();
};