#include "PmergeMe.hpp"

//	std::vector container
void	ParseArgs(std::vector<std::string> args)
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

void	ConvertToInt(std::vector<std::pair<int, int> > &nums, std::vector<std::string> args)
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

void    SortNums(std::vector<std::pair<int, int> > &nums)
{
	std::vector<std::pair<int, int> >::iterator	it;

	it = nums.begin();
	while (it != nums.end()) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
		it++;
	}
}

void	SortPairs(std::vector<std::pair<int, int> > &nums)
{
	std::vector<std::pair<int, int> >::iterator	it;
	std::vector<std::pair<int, int> >::iterator	j;
	std::pair<int, int>	key;

	for (it = nums.begin() + 1; it != nums.end(); ++it) {
		j = it;
		key = *it;
		while (j != nums.begin() && (j - 1)->first > key.first) {
			*j = *(j - 1);
			--j;
		}
		*j = key;
	}
}

void    SplitPairs(std::vector<std::pair<int, int> > &nums, std::vector<int> &main, std::vector<int> &pend)
{
	std::vector<std::pair<int, int> >::iterator	it;

	if (nums.begin()->second != -1)
		main.push_back(nums.begin()->second);
	main.push_back(nums.begin()->first);
	for (it = nums.begin() + 1; it != nums.end(); it++) {
		main.push_back(it->first);
		if (it->second != -1)
			pend.push_back(it->second);
	}
}


void GenerateJacobNums(std::vector<int> &jacobNums, size_t pendSize)
{
	int	j;

	jacobNums.push_back(0);
	jacobNums.push_back(1);

	while (jacobNums.back() < static_cast<int>(pendSize)) {
		j = jacobNums[jacobNums.size() - 1] + jacobNums[jacobNums.size() - 2] * 2;
		jacobNums.push_back(j);
	}
	jacobNums.erase(jacobNums.begin());
	jacobNums.erase(jacobNums.begin());
}

void	InsertNum(std::vector<int> &main, int val)
{
	int left = 0;
	int	right = main.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (main[0] >= val) {
			main.insert(main.begin(), val);
			return ;
		}
		else if (main[mid] <= val && ( mid + 1 >= static_cast<int>(main.size()) || main[mid + 1] >= val)) {
			main.insert(main.begin() + mid + 1, val);
			return ;
		}
		else if (main[mid] < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

void    InsertToMain(std::vector<int> &jacobNums, std::vector<int> &main, std::vector<int> &pend)
{
	int	currJ;
	int	prevJ;

	if (!pend.size())
		return ;
	else if (pend.size() == 1)
		return (InsertNum(main, pend.at(0)));
	InsertNum(main, pend.at(0));
	InsertNum(main, pend.at(1));
	if (pend.size() == 2)
		return ;
	for (size_t i = 1; i < jacobNums.size(); i++) {
		currJ = jacobNums.at(i);
		prevJ = jacobNums.at(i - 1);
		if (prevJ > static_cast<int>(pend.size()))
			break;
		while (currJ > prevJ) {
			if (currJ >= static_cast<int>(pend.size())) {
				currJ--;
				continue;
			}
			InsertNum(main, pend.at(currJ--));
		}
		

	}
}

//	std::deque container

void	ParseArgs(std::deque<std::string> args)
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

void	ConvertToInt(std::deque<std::pair<int, int> > &nums, std::deque<std::string> args)
{
	std::deque<std::string>::iterator	it;

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

void	SortNums(std::deque<std::pair<int, int> > &nums)
{
	std::deque<std::pair<int, int> >::iterator	it;

	it = nums.begin();
	while (it != nums.end()) {
		if (it->first < it->second)
			std::swap(it->first, it->second);
		it++;
	}
}

void	SortPairs(std::deque<std::pair<int, int> > &nums)
{
	std::deque<std::pair<int, int> >::iterator	it;
	std::deque<std::pair<int, int> >::iterator	j;
	std::pair<int, int>	key;

	for (it = nums.begin() + 1; it != nums.end(); ++it) {
		j = it;
		key = *it;
		while (j != nums.begin() && (j - 1)->first > key.first) {
			*j = *(j - 1);
			--j;
		}
		*j = key;
	}
}

void	SplitPairs(std::deque<std::pair<int, int> > &nums, std::deque<int> &main, std::deque<int> &pend)
{
	std::deque<std::pair<int, int> >::iterator	it;

	if (nums.begin()->second != -1)
		main.push_back(nums.begin()->second);
	main.push_back(nums.begin()->first);
	for (it = nums.begin() + 1; it != nums.end(); it++) {
		main.push_back(it->first);
		if (it->second != -1)
			pend.push_back(it->second);
	}
}


void	GenerateJacobNums(std::deque<int> &jacobNums, size_t pendSize)
{
	int	j;

	jacobNums.push_back(0);
	jacobNums.push_back(1);

	while (jacobNums.back() < static_cast<int>(pendSize)) {
		j = jacobNums[jacobNums.size() - 1] + jacobNums[jacobNums.size() - 2] * 2;
		jacobNums.push_back(j);
	}
	jacobNums.erase(jacobNums.begin());
	jacobNums.erase(jacobNums.begin());
}

void	InsertNum(std::deque<int> &main, int val)
{
	int left = 0;
	int	right = main.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (main[0] >= val) {
			main.insert(main.begin(), val);
			return ;
		}
		else if (main[mid] <= val && ( mid + 1 >= static_cast<int>(main.size()) || main[mid + 1] >= val)) {
			main.insert(main.begin() + mid + 1, val);
			return ;
		}
		else if (main[mid] < val)
			left = mid + 1;
		else
			right = mid - 1;
	}
}

void	InsertToMain(std::deque<int> &jacobNums, std::deque<int> &main, std::deque<int> &pend)
{
	int	currJ;
	int	prevJ;

	if (!pend.size())
		return ;
	else if (pend.size() == 1)
		return (InsertNum(main, pend.at(0)));
	InsertNum(main, pend.at(0));
	InsertNum(main, pend.at(1));
	if (pend.size() == 2)
		return ;
	for (size_t i = 1; i < jacobNums.size(); i++) {
		currJ = jacobNums.at(i);
		prevJ = jacobNums.at(i - 1);
		if (prevJ > static_cast<int>(pend.size()))
			break;
		while (currJ > prevJ) {
			if (currJ >= static_cast<int>(pend.size())) {
				currJ--;
				continue;
			}
			InsertNum(main, pend.at(currJ--));
		}
		

	}
}