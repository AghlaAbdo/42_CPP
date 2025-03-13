#include <iostream>
#include "RPN.hpp"

void	parseArg(std::string const &arg)
{
	int	joinedChars = 0;

	for (size_t i = 0; i < arg.size(); i++) {
		if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '+' && arg[i] != '-'
			&& arg[i] != '*' && arg[i] != '/' && arg[i] != ' ')
			throw std::runtime_error("Error: invalid character");
		if (arg[i] != ' ')
			joinedChars++;
		else
			joinedChars = 0;
		if (joinedChars > 1)
			throw std::runtime_error("Error: need to separate characters");
	}
}

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Requires a single argument" << std::endl;
		return (1);
	}
	try {
		parseArg(av[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	try {
		calcExpression(av[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (1);
	}

	return (0);
}
