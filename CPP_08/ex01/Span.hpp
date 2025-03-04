#pragma once

#include <iostream>
#include <vector>

class	Span {
private:
	std::vector<int>	numbers;
	unsigned int		maxSize;
	// unsigned int		size;

public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &copy);
	~Span();
	Span	&operator=(const Span &copy);

	void	addNumber(int num);
	int		getNumber(unsigned int idx);
	int		shortestSpan(void);
	int		longestSpan(void);
	void	addBunchOfNumbers(int *begin, int size);
};
