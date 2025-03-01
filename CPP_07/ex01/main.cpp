#include "iter.hpp"

void	toUpper(char& c)
{
	c = toupper(c);
}

int	main(void)
{
	 // Test case 1: Array of integers
    int arr1[] = {1, 2, 3, 4, 5};
	std::cout << "----- Instantiated function template -----\n" << std::endl;
    std::cout << "Test case 1: Array of integers" << std::endl;
    iter(arr1, 5, printValue<int>);
    std::cout << "\n\n";

    // Test case 2: Array of doubles
    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << "Test case 2: Array of doubles" << std::endl;
    iter(arr2, 5, printValue<double>);
    std::cout << "\n\n";

    // Test case 3: Array of strings
    std::string arr3[] = {"Hello", "World", "Test", "C++"};
    std::cout << "Test case 3: Array of strings" << std::endl;
    iter(arr3, 4, printValue<std::string>);
    std::cout << "\n\n";


    // Test case 4: Empty array
    int arr5[] = {};
    std::cout << "Test case 4: Empty array" << std::endl;
    iter(arr5, 0, printValue<int>);
    std::cout << "\n\n";

	std::cout << "----- Normal function -----\n" << std::endl;
    // Test case 5: Array of characters
    char arr4[] = {'a', 'B', 'c', 'd', 'E'};
    std::cout << "Test case 5: Array of characters converted to uppercase" << std::endl;
    iter(arr4, 5, toUpper);
    iter(arr4, 5, printValue<char>);
    std::cout << "\n";

	return (0);
}