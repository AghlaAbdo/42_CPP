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

void    fstSplitPairs(std::vector<std::pair<int, int> > &nums, std::vector<int> &main, std::vector<int> &pend)
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


void fstGenerateJacobNums(std::vector<int> &jacobNums, size_t pendSize)
{
	// size_t	indx = 1;
	// size_t	dist = 0;
	int		j;

	jacobNums.push_back(0);
	jacobNums.push_back(1);

	// std::cout << "pend size: " << pendSize << std::endl;
	while (jacobNums.back() < static_cast<int>(pendSize)) {
		j = jacobNums[jacobNums.size() - 1] + jacobNums[jacobNums.size() - 2] * 2;
		jacobNums.push_back(j);
	}
	jacobNums.erase(jacobNums.begin());
	jacobNums.erase(jacobNums.begin());
	// while (indx < (jacobNums.size()) && jacobNums.size() < pendSize) {
	// 	int prev_idx = indx - 1 - dist;
	// 	if (prev_idx < 0)
	// 		prev_idx = 0;
	// 	int prev = jacobNums.at(prev_idx);
	// 	// std::cout << "\t\tcurr: " << *curr << " | prev: " << prev << std::endl;

	// 	j = jacobNums.at(indx);
	// 	dist = 0;
	// 	while (--j > prev && jacobNums.size() < pendSize + 2) {
	// 		dist++;
	// 		if (indx + dist >= (jacobNums.size()))
	// 		jacobNums.push_back(j);
	// 		else
	// 		jacobNums.insert(jacobNums.begin() + indx + dist, j);
	// 		// std::cout << "\t insert at: " << jacobNums[indx + dist] << std::endl;
	// 	}
	// 	indx += dist + 1;
	// }
	// std::cout << "jacobNums size: " << jacobNums.size() << std::endl;

	// std::cout << "Jacobsthal sequence:" << std::endl;
	// for (size_t i = 0; i < jacobNums.size(); i++)
	// 	std::cout << jacobNums[i] << " ";
	// std::cout << std::endl;
}

void	fstInsertNum(std::vector<int> &main, int val)
{
	int left = 0;
	int	right = main.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

		if (main[0] > val) {
			// std::cout << "place to insert: " << val << " is: At Begining" << std::endl;
			main.insert(main.begin(), val);
			return ;
		}
        else if (main[mid] < val && ( mid + 1 >= static_cast<int>(main.size()) || main[mid + 1] > val)) {
			// std::cout << "place to insert: " << val << " is: " << main[mid] << std::endl;
			main.insert(main.begin() + mid + 1, val);
			return ;
		}
        else if (main[mid] < val)
            left = mid + 1;
        else
            right = mid - 1;
    }

}

void    fstInsertToMain(std::vector<int> &jacobNums, std::vector<int> &main, std::vector<int> &pend)
{
	int	currJ;
	int	prevJ;

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
			fstInsertNum(main, pend.at(currJ--));
		}
		

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
