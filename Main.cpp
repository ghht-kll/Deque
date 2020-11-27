#include <iostream>
#include <chrono>
#include "MyDeque.h"

int main()
{
	setlocale(LC_ALL, "Rus");

	MyDeque deque;
	int x = 0;
	std::cout << " -> "; std::cin >> x;
	for (int i = 0; i < x / 2; i++)
	{
		deque.push_back(std::rand() % 10);
		deque.push_front(std::rand() % 10);
	}
	MyDeque copydeque(&deque);
	std::cout << "до: ";

	for (unsigned int i = copydeque.getSize(); i > 0; --i)
	{
		std::cout << deque.pop_front() << " ";
	}
	auto start = std::chrono::system_clock::now();
	copydeque.sort();
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cout << "\n\nпосле: ";
	for (unsigned int i = copydeque.getSize(); i > 0; --i)
	{
		std::cout << copydeque.pop_front() << " ";
	}
	std::cout << "\nВремя сортировки: " << elapsed.count() << "\n";
	system("pause");
	std::cin >> x;
	return 0;
}
