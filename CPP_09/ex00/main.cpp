#include <iostream>
#include <map>
#include <sstream>
#include "BitcoinExchange.hpp"
#include <cstdio>

int	main(int ac, char **av)
{
	std::map<std::string, double>	data;

	if (ac != 2) {
		std::cout << "Requires a single input file" << std::endl;
		return (1);
	}

	try {
		data = readData();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	try {
		readInput(data, av[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}