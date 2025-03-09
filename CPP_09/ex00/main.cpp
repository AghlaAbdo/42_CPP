#include <iostream>
#include <map>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Requires a single input file" << std::endl;
	}

	std::map<std::string, int>	data;
	try {
		data = readData();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	(void)av;

	return (0);
}