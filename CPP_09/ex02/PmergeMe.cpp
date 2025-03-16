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

void	fstConvertToInt(std::vector<int> &nums, std::vector<std::string> args)
{
	std::vector<std::string>::iterator	it;

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
