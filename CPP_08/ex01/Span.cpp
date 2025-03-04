#include <algorithm>
#include <climits>
#include "Span.hpp"

Span::Span(void)
	: maxSize(0) {}

Span::Span(unsigned int n)
	: maxSize(n) {}

Span::Span(const Span &copy)
{
	maxSize = copy.maxSize;
	numbers.insert(numbers.end(), copy.numbers.begin(), copy.numbers.end());
}

Span::~Span() {}

Span	&Span::operator=(const Span &copy)
{
	numbers.clear();
	maxSize = copy.maxSize;
	numbers.insert(numbers.end(), copy.numbers.begin(), copy.numbers.end());
	return (*this);
}

void	Span::addNumber(int num)
{
	if (numbers.size() + 1 > maxSize)
		throw std::out_of_range("You hit the size limit");
	numbers.push_back(num);
}

int	Span::getNumber(unsigned int idx)
{
	return (numbers.at(idx));
}

int	Span::shortestSpan(void)
{
	if (numbers.size() < 2)
		throw std::runtime_error("Not enough elements to calc shortest span");

	std::vector<int>	sorted = numbers;
	std::sort(sorted.begin(), sorted.end());
	int	min = INT_MAX;

	for (size_t i = 1; i < sorted.size(); i++) {
		int	span = sorted[i] - sorted[i -1];
		if (span < min)
			min = span;
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (numbers.size() < 2)
		throw std::out_of_range("Not enough elements to calc longest span");

	std::vector<int>::iterator	max;
	std::vector<int>::iterator	min;

	max = std::max_element(numbers.begin(), numbers.end());
	min = std::min_element(numbers.begin(), numbers.end());
	
	return (*max - *min);
}

void	Span::addBunchOfNumbers(int *begin, int size)
{
	if (numbers.size() + size > maxSize) {
		size = maxSize - numbers.size();
		numbers.insert(numbers.end(), begin, begin + size);
		throw std::runtime_error("You hit the size limit, Not all numbers added");
	}
	numbers.insert(numbers.end(), begin, begin + size);
}
