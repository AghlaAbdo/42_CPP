#pragma once

#include <iostream>
#include <sstream>
#include <cstdio>
#include <climits>
#include <cfloat>
#include <cmath>
#include <cerrno>
#include <cstdlib>

class   ScalarConverter {
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &copy);
	~ScalarConverter(void);
	ScalarConverter	&operator=(ScalarConverter const &rhs);
	static void	convertFromChar(std::string &str);
	static void	convertFromInt(std::string &str);
	static void	convertFromFloat(std::string &str);
	static void	convertFromDouble(std::string &str);
	static int	countDots(std::string &str);
	static int	onlyDeciaml(std::string &str);
	static int	onlyNonDeciaml(std::string &str);

public:
	static void convert(std::string str);
};