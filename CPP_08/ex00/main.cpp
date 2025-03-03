#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "easyfind.hpp"

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 5};

	std::vector<int>	vec;
	std::copy(arr, arr + 5, std::inserter(vec, vec.end()));

	std::list<int>		lst;
	std::copy(arr, arr + 5, std::inserter(lst, lst.end()));

	try {
		std::vector<int>::iterator	it = easyfind(vec, 2);
		std::cout << "Found value in 'vec': " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::iterator	it = easyfind(lst, 5);
		std::cout << "Found value in 'lst': " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator	it = easyfind(vec, 24);
		std::cout << "Found value in 'vec': " << *it << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}