#include "MyDeque.h"

bool MyDeque::checkSize(unsigned int index)
{
	if (this->sizeDeque >= index) return true;
	else return false;
}

void MyDeque::set_front(unsigned int index, double value)
{
	if (checkSize(index))
	{
		for (unsigned int i = 0; i < index; i++)
		{
			this->push_back(this->pop_front());
		}
		this->pop_front();
		this->push_front(value);
		for (unsigned int i = 0; i < index; i++)
		{
			this->push_front(this->pop_back());
		}
	}
}

int MyDeque::get_front(unsigned int index)
{
	int result(0);
	if (checkSize(index))
	{
		for (unsigned int i = 0; i < index; i++)
		{
			this->push_back(this->pop_front());
		}
		result = this->front();
		for (unsigned int i = 0; i < index; i++)
		{
			this->push_front(this->pop_back());
		}
	}
	return result;
}

MyDeque::MyDeque() : firstElement(nullptr), lastElement(nullptr), sizeDeque(0)
{	}

MyDeque::MyDeque(MyDeque* deque) : MyDeque()
{
	Element* element = deque->firstElement;
	for (unsigned int i = deque->getSize(); i > 0; --i)
	{
		push_back(element->value);
		element = element->nextElement;
	}
}

void MyDeque::push_back(double value)
{
	Element* element = new Element;
	element->value = value;
	this->sizeDeque++;
	if (!this->firstElement)
	{
		this->firstElement = element;
		this->lastElement = this->firstElement;
	}
	else
	{
		element->previousElement = this->lastElement;
		this->lastElement->nextElement = element;
		this->lastElement = element;
	}
}

void MyDeque::push_front(double value)
{
	Element* element = new Element;
	element->value = value;
	this->sizeDeque++;
	if (!this->firstElement)
	{
		this->firstElement = element;
		this->lastElement = this->firstElement;
	}
	else
	{
		element->nextElement = this->firstElement;
		this->firstElement->previousElement = element;
		this->firstElement = element;
	}
}

int MyDeque::pop_back()
{
	double result(0);
	if (this->sizeDeque != 0)
	{
		result = this->lastElement->value;
		if (this->sizeDeque > 1)
		{
			Element* element = this->lastElement;
			this->lastElement = this->lastElement->previousElement;
			this->lastElement->nextElement = nullptr;
			delete element;
			this->sizeDeque--;
		}
		else
		{
			this->firstElement = this->lastElement = 0;
			this->sizeDeque--;
		}
	}
	return result;
}

int MyDeque::pop_front()
{
	double result(0);
	if (this->sizeDeque != 0)
	{
		result = this->firstElement->value;
		if (this->firstElement->nextElement)
		{
			Element* element = this->firstElement;
			this->firstElement = this->firstElement->nextElement;
			if (this->sizeDeque != 1)
			{
				this->firstElement->previousElement = nullptr;
			}
			delete element;
			this->sizeDeque--;
		}
		else if (this->firstElement == this->lastElement)
		{
			this->firstElement->nextElement = nullptr;
			this->firstElement = nullptr;
			delete this->firstElement;
			this->sizeDeque = 0;
		}
	}
	return result;
}

int MyDeque::back()
{
	if (!this->sizeDeque == 0) return this->lastElement->value;
	else
	{
		std::cout << "список пуст ошибка" << std::endl;
		std::exit(-1);
	}
}

int MyDeque::front()
{
	if (!this->sizeDeque == 0) return this->firstElement->value;
	else
	{
		std::cout << "список пуст ошибка" << std::endl;
		std::exit(-1);
	}
}

void MyDeque::clear()
{
	for (unsigned int i = getSize(); i > 0; --i)
	{
		this->lastElement = this->firstElement->nextElement;
		delete this->firstElement;
		this->firstElement = this->lastElement;
	}
	this->sizeDeque = 0;
}

void MyDeque::clear_back(unsigned int index)
{
	if (checkSize(index))
	{
		Element* element;
		for (unsigned int i = 0; i < index; i++)
		{
			element = this->lastElement;
			this->lastElement = element->previousElement;
			delete element;
		}
		this->sizeDeque -= index;
	}
}

void MyDeque::clear_front(unsigned int index)
{
	if (checkSize(index))
	{
		Element* element;
		for (unsigned int i = 0; i < index; i++)
		{
			element = this->firstElement;
			this->firstElement = element->nextElement;
			delete element;
		}
		this->sizeDeque -= index;
	}
}

void MyDeque::sort()
{
	double temp(0);
	int item(0);
	for (int counter = 1; counter < getSize(); counter++)
	{
		temp = get_front(counter);
		item = counter - 1;
		while (get_front(item) > temp && item >= 0)
		{
			set_front(item + 1, get_front(item));
			set_front(item, temp);
			item--;
		}
	}
}

unsigned int MyDeque::getSize()
{
	return this->sizeDeque;
}

MyDeque::~MyDeque()
{
	clear();
}
