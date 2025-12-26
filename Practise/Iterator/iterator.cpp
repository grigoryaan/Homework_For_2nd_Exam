#include <iostream>
#include <vector>
#include <list>

int main() {
	std::vector<int> vec = { 100, 505, 44, 33, 71, 89 };
	std::list<int> lst = { 10, 20, 30, 40 };

	std::cout << "Vector: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it += 2)
	{
		std::cout << *it << " ";
	}

	std::cout <<"\nList: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
}
