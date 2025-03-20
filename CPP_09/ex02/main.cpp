#include "PmergeMe.hpp"

long long	getTime() {
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return (tv.tv_sec * 1e6 + tv.tv_usec);
}

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Requires arguments to sort" << std::endl;
		return (1);
	}

	std::vector<std::string>	args(av + 1, av + ac);
	std::vector<std::pair<int, int> >	before;
	std::vector<int>	after;
	long long elapsedVec;
	long long elapsedDeq;

	// std::vector container
	{
		long long	startTime = getTime();
		std::vector<std::string>	args(av + 1, av + ac);
		std::vector<std::pair<int, int> >	nums;
		std::vector<int>	main;
		std::vector<int>	pend;
		std::vector<int>	jacobNums;

		try {
			ParseArgs(args);
			ConvertToInt(nums, args);
			SortNums(nums);
			SortPairs(nums);
			SplitPairs(nums, main, pend);
			GenerateJacobNums(jacobNums, pend.size());
			InsertToMain(jacobNums, main, pend);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
		elapsedVec = getTime() - startTime;
		after = main;
	}

	//	std::deque container
	{
		long long	startTime = getTime();
		std::deque<std::string>	args(av +1, av +ac);
		std::deque<std::pair<int, int> >	nums;
		std::deque<int>	main;
		std::deque<int>	pend;
		std::deque<int>	jacobNums;

		try {
			ParseArgs(args);
			ConvertToInt(nums, args);
			SortNums(nums);
			SortPairs(nums);
			SplitPairs(nums, main, pend);
			GenerateJacobNums(jacobNums, pend.size());
			InsertToMain(jacobNums, main, pend);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
		elapsedDeq = getTime() - startTime;
	}

	ParseArgs(args);
	ConvertToInt(before, args);

	std::cout << "Before:\t";
	std::vector<std::pair<int, int> >::iterator	pairIt;
	for (pairIt = before.begin(); pairIt != before.end(); pairIt++) {
		std::cout << pairIt->first << " ";
		if (pairIt->second != -1)
			 std::cout << pairIt->second << " ";
	}
	std::cout << std::endl;

	std::cout << "After:\t";
	std::vector<int>::iterator	it;
	for (it = after.begin(); it != after.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std:: cout << "Time to process a range of " << after.size()
		<< " elements with std::vector : " << elapsedVec << " microseconds" << std::endl;
	std:: cout << "Time to process a range of " << after.size()
		<< " elements with std::deque : " << elapsedDeq << " microseconds"  << std::endl;

	return (0);
}
