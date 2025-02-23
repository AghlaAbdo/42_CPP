#include "ScalarConverter.hpp"

// double stringToDouble(const std::string& str) {
//     std::stringstream ss(str);
//     double number;

//     ss >> number;
//     if (ss.fail())
//         return (-1);
    
//     return number;
// }

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Need one parameter!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	
	return (0);
}