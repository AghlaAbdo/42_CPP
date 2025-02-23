#include "ScalarConverter.hpp"

int countDots(std::string str)
{
	int count = 0;

	for (size_t i = 0; i < str.length(); i++)
		if (str[i] == '.')
			count++;
	return (count);
}

int onlyDeciaml(std::string str)
{
	size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.length() - 1; i++) {
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
	}
	if (i > 1 && !(str[i] >= '0' && str[i] <= '9') && str[i] != 'f')
		return (0);
	return (1);
}

int onlyNonDeciaml(std::string str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
	}
	return (1);
}

double stringToDouble(const std::string& str) {
	std::stringstream ss(str);
	double number;

	ss >> number;
	if (ss.fail())
		return (-1);
	
	return number;
}

void    ScalarConverter::convertFromChar(std::string &str)
{
	char    c = str[0];
	int     i = static_cast<int>(c);
	float   f = static_cast<float>(c);
	double  d = static_cast<double>(c);

	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f;
	if (f == i)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (d == i)
		std::cout << ".0";
	std::cout << std::endl;
}

void    ScalarConverter::convertFromFloat(std::string &str)
{
	std::stringstream ss(str);
	float f;

	ss >> f;
	char    c = static_cast<char>(f);
	int     i = static_cast<int>(f);
	double  d = static_cast<double>(f);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f;
	if (f == i)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (d == i)
		std::cout << ".0";
	std::cout << std::endl;
}

void    ScalarConverter::convertFromDouble(std::string &str)
{
	std::stringstream ss(str);
	double d;

	ss >> d;
	char    c = static_cast<char>(d);
	int     i = static_cast<int>(d);
	float	f = static_cast<float>(d);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f;
	if (f == i)
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << d;
	if (d == i)
		std::cout << ".0";
	std::cout << std::endl;

}

void	ScalarConverter::convertFromInt(std::string &str)
{
	std::stringstream ss(str);
	int i;

	ss >> i;
	char    c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<int>(i);
	if (std::isprint(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non printable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;

}

void    ScalarConverter::convert(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		return ;
	}
	if (str == "-inf" || str == "+inf" || str == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str + "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return ;
	}
	if (countDots(str) > 1 || (!onlyDeciaml(str) && !onlyNonDeciaml(str))
		|| (onlyNonDeciaml(str) && str.length() > 1)) {
		std::cout << "Invalid input." << std::endl;
		return ;
	}
	if (onlyNonDeciaml(str))
		convertFromChar(str);
	else if (str.find('f') != std::string::npos)
		convertFromFloat(str);
	else if (str.find('.') != std::string::npos)
		convertFromDouble(str);
	else
	    convertFromInt(str);
}

