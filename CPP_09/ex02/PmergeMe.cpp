#include "PmergeMe.hpp"

//	std::vector container

void	fstParseArgs(std::vector<std::string> args)
{
	std::vector<std::string>::iterator	it;

	for (it = args.begin(); it != args.end(); it++) {
		for (size_t i = 0; i < it->size(); i++) {
			if (!(it->at(i) >= '0' && it->at(i) <= '9'))
				throw std::runtime_error("Error");
		}
		if (it->size() > 10)
			throw std::runtime_error("Error: too large number");
	}
}

void	fstConvertToInt(std::vector<std::pair<int, int> > &nums, std::vector<std::string> args)
{
	std::vector<std::string>::iterator	it;

	for (it = args.begin(); it != args.end(); it++) {
		std::istringstream	ss(*it);
		long	num1;
		long	num2;
		ss >> num1;
		if (ss.fail())
			throw std::runtime_error("Error: Couldn't convert to int");
		if (num1 > INT_MAX)
			throw std::runtime_error("Error: too large number");
		
		it++;
		if (it == args.end()) {
			nums.push_back(std::make_pair(num1, -1));
			break;
		}
		ss.str(*it);
		ss.clear();
		ss >> num2;
		if (ss.fail())
			throw std::runtime_error("Error: Couldn't convert to int");
		if (num2 > INT_MAX)
			throw std::runtime_error("Error: too large number");

		nums.push_back(std::make_pair(num1, num2));
	}
}

void    fstSortNums(std::vector<std::pair<int, int> > &nums)
{
	std::vector<std::pair<int, int> >::iterator	it;

	it = nums.begin();
	while (it != nums.end()) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
		it++;
	}
}

void	fstSortPairs(std::vector<std::pair<int, int> > &nums)
{
	std::vector<std::pair<int, int> >::iterator	curr;
	std::vector<std::pair<int, int> >::iterator	it;
	int		i = 0;

	for (curr = nums.begin() + 1; curr != nums.end(); curr++) {
		it = curr - 1;
		while (it != nums.begin() && curr->first < it->first) {
			it--;
			if (it != nums.end() && !(curr->first < it->first)) {
				it++;
				break;
			}
		}
		if (curr->first < it->first) {
			std::pair<int, int>	pair = *curr;
			nums.erase(curr);
			nums.insert(it, pair);
			curr = nums.begin() + i + 1;
		}
		i++;
	}
}

//	std::deque container

void	secParseArgs(std::deque<std::string> args)
{
	std::deque<std::string>::iterator	it;

	for (it = args.begin(); it != args.end(); it++) {
		for (size_t i = 0; i < it->size(); i++) {
			if (!(it->at(i) >= '0' && it->at(i) <= '9'))
				throw std::runtime_error("Error");
		}
		if (it->size() > 10)
			throw std::runtime_error("Error: too large number");
	}
}

void	secConvertToInt(std::deque<int> &nums, std::deque<std::string> args)
{
	std::deque<std::string>::iterator	it;

	for (it = args.begin(); it != args.end(); it++) {
		std::istringstream	ss(*it);
		long	num;
		ss >> num;
		if (ss.fail())
			throw std::runtime_error("Error: ss.fail()");
		if (num > INT_MAX)
			throw std::runtime_error("Error: too large number");
		nums.push_back(num);
	}
}
