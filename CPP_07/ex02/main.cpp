#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Array.hpp"

#define MAX_VAL 750

struct Person {
	std::string name;
	int age;
	Person(const std::string& name, int age) : name(name), age(age) {}
	Person() : name(""), age(0) {}
};

int main(int, char**)
{
	std::cout << "------ Array of strings ------" << std::endl;
   {
		Array<std::string> arr(3);
		
		arr[0] = "Hello";
		arr[1] = "World";
		arr[2] = "Test";

		for (size_t i = 0; i < arr.size(); ++i)
			std::cout << "arr[" << i << "] = " << arr[i] << std::endl;

		Array<std::string> arr2 = arr;

		arr[0] = "changed";
		arr[1] = "changed";
		arr[2] = "changed";
		std::cout << "\nAssigned arr to arr2 and changed arr:\n";
		for (size_t i = 0; i < arr2.size(); ++i)
			std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;

		Array<std::string> arr3(arr2);

		arr2[0] = "changed";
		arr2[1] = "changed";
		arr2[2] = "changed";
		std::cout << "\nCopied arr2 to arr3 and changed arr2:\n";
		for (size_t i = 0; i < arr3.size(); ++i)
			std::cout << "arr3[" << i << "] = " << arr3[i] << std::endl;
	}
	
	std::cout << "\n------ Array of ints ------" << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		std::cout << "Test if values of both 'number' and 'mirror' are equal, should quiet if not:" << std::endl;

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		std::cout << "\nTrying to access an index out of range:" << std::endl;
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
	
	std::cout << "\n------ Array of custom type ------" << std::endl;
	{
		Array<Person> arr(2);
		arr[0] = Person("Mike", 30);
		arr[1] = Person("Bob", 25);

		for (size_t i = 0; i < arr.size(); ++i)
			std::cout << arr[i].name << " (" << arr[i].age << ")" << std::endl;
	}

	std::cout << "\n------ Creating an empty array ------" << std::endl;
	{
		Array<double>	arr1(0);
		Array<float>	arr2;
		std::cout << "Accessing index 0" << std::endl;
		try {
			std::cout << arr1[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		try {
			std::cout << arr2[0] << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	
	return 0;
}
