#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base*	generate(void)
{
	std::srand(std::time(0));
	int randNum = std::rand() % 3 + 1;
	switch (randNum) {
		case 1:
			return (new A());
		case 2:
			return (new B());
		case 3:
			return (new C());
		default:
			perror("Failed to generate random number");
			return (NULL);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
	else
		std::cout << "Unknown";
}

void	identify(Base& p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch (std::bad_cast &e) {
		try {
			dynamic_cast<B&>(p);
			std::cout << "B";
		}
		catch (std::bad_cast &e) {
			try {
				dynamic_cast<C&>(p);
				std::cout << "C";
			}
			catch (std::bad_cast &e) {
				std::cout << "Unknown";
			}
		}
	}
}

int	main(void)
{
	std::cout << "------ Identify using a pointer ------" << std::endl;

	Base*	ptr1 = generate();
	std::cout << "obj generated in ptr1: ";
	identify(ptr1);
	std::cout << std::endl;

	std::cout << "\n------ Identify using a reference ------" << std::endl;

	Base*	ptr2 = generate();
	std::cout << "obj generated in ptr2: ";
	identify(*ptr2);
	std::cout << std::endl;

	delete ptr1;
	delete ptr2;
	return (0);
}
