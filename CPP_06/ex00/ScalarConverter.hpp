#pragma once

#include <iostream>
#include <sstream>
#include <cstdio>

class   ScalarConverter {
private:
	ScalarConverter(void);
	static void	convertFromChar(std::string &str);
	static void	convertFromInt(std::string &str);
	static void	convertFromFloat(std::string &str);
	static void	convertFromDouble(std::string &str);

public:
	static void convert(std::string str);
};