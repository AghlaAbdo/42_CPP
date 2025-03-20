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
	std::deque<int>		afterDeq;
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
			fstParseArgs(args);
			fstConvertToInt(nums, args);
			fstSortNums(nums);
			fstSortPairs(nums);
			// std::cout << "\n----- Sorted pairs Vector: -----" << std::endl;
			// std::vector<std::pair<int, int> >::iterator dIt;
			// for (dIt = nums.begin(); dIt != nums.end(); dIt++) {
			// 	std::cout << dIt->first << " " << dIt->second << " |" << std::endl;
			// }
			fstSplitPairs(nums, main, pend);
			fstGenerateJacobNums(jacobNums, pend.size());
			fstInsertToMain(jacobNums, main, pend);
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
			secParseArgs(args);
			secConvertToInt(nums, args);
			secSortNums(nums);
			secSortPairs(nums);
			// std::cout << "\n----- Sorted pairs Deque: -----" << std::endl;
			// std::deque<std::pair<int, int> >::iterator dIt;
			// for (dIt = nums.begin(); dIt != nums.end(); dIt++) {
			// 	std::cout << dIt->first << " " << dIt->second << " |" << std::endl;
			// }
			secSplitPairs(nums, main, pend);
			secGenerateJacobNums(jacobNums, pend.size());
			secInsertToMain(jacobNums, main, pend);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
		elapsedDeq = getTime() - startTime;
		afterDeq = main;
	}

	fstParseArgs(args);
	fstConvertToInt(before, args);

	std::cout << "Before: ";
	std::vector<std::pair<int, int> >::iterator	pairIt;
	for (pairIt = before.begin(); pairIt != before.end(); pairIt++) {
		std::cout << pairIt->first << " ";
		if (pairIt->second != -1)
			 std::cout << pairIt->second << " ";
	}
	std::cout << std::endl;

	std::cout << "After: ";
	std::vector<int>::iterator	it;
	for (it = after.begin(); it != after.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Deque: ";
	std::deque<int>::iterator	it2;
	for (it2 = afterDeq.begin(); it2 != afterDeq.end(); it2++)
		std::cout << *it2 << " ";
	std::cout << std::endl;

	std:: cout << "Time to process a range of " << after.size()
		<< " elements with std::vector : " << elapsedVec << std::endl;
	std:: cout << "Time to process a range of " << after.size()
		<< " elements with std::deque : " << elapsedDeq << std::endl;

	return (0);
}
