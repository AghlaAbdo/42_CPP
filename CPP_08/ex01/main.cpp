#include "Span.hpp"
#include <iostream>

int	main(void)
{
	{
		Span	span1;
		Span	span2(20);
		
		for (int i = 0; i < 20; i++) {
			try {
				span2.addNumber(i);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << "----- Numbers added in span2: ------" << std::endl;
		for (int i = 0; i < 20; i++) {
			try {
				std::cout << span2.getNumber(i) << " ";
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		
		std::cout << "\n----- Copied span2 into span1 using assignment operator: ------" << std::endl;
		span1 = span2;
		for (int i = 0; i < 20; i++) {
			try {
				std::cout << span1.getNumber(i) << " ";
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;

		std::cout << "\n----- Copied span1 into span2 using copy constructor: ------" << std::endl;
		Span	span3(span1);
		for (int i = 0; i < 20; i++) {
			try {
				std::cout << span3.getNumber(i) << " ";
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << "Shortest span in span1: " << span1.shortestSpan() << std::endl;
		std::cout << "Longest span in span1: " << span1.longestSpan() << std::endl;
	}

	std::cout << "\n------ Adding a bunch of numbers at once ------" << std::endl;
	{
		int		nums[] = {498, 98, 5656, 23, 6, 76, 45, 34, 456, 56};
		Span	sp(10);
		try {
			sp.addBunchOfNumbers(nums, 10);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		for (int i = 0; i < 10; i++) {
			try {
				std::cout << sp.getNumber(i) << " ";
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n------ Adding 10.000 numbers one at a time ------" << std::endl;
	{
		Span 	sp(10000);
		for (int i = 0; i < 10000; i++) {
			try  {
				sp.addNumber(i);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n------ Adding 100.000 numbers at once ------" << std::endl;
	{
		Span	sp(100000);
		int		nums[100000];
		for (int i = 0; i < 100000; i++)
			nums[i] = i;
		try {
			sp.addBunchOfNumbers(nums, 100000);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}

	std::cout << "\n------ Adding more numbers than the array can hold ------" << std::endl;
	{
		Span	sp(5);
		for (int i = 0; i < 8; i++) {
			try {
				sp.addNumber(i);
			}
			catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
	}

	std::cout << "\n------ Subject test: -----" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return (0);
}
