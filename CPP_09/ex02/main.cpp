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

			std::cout << "Befor: ";
			std::vector<std::pair<int, int> >::iterator	pairIt;
			for (pairIt = nums.begin(); pairIt != nums.end(); pairIt++) {
				std::cout << pairIt->first << " " << pairIt->second << " ";
			}
			std::cout << std::endl;
			fstSortNums(nums);


			fstSortPairs(nums);
			// std::cout << "33" << std::endl;
			fstSplitPairs(nums, main, pend);

			// std::cout << ""\n----- pend: -----" << std::endl";
			// std::vector<int>::iterator	it;
			// for (it = pend.begin(); it != pend.end(); it++)
			// std::cout << *it << " ";
			// std::cout << std::endl;

			// std::cout << "44" << std::endl;
			fstGenerateJacobNums(jacobNums, pend.size());
			// std::cout << "55" << std::endl;
			fstInsertToMain(jacobNums, main, pend);
			// std::cout << "66" << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}

		std::cout << "After: ";
		std::vector<int>::iterator	it;
		for (it = main.begin(); it != main.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		long long elapsed = getTime() - startTime;
		std:: cout << "Time to process a range of " << main.size()
			<< "5 elements with std::vector : " << elapsed << std::endl;
	}

	//	std::deque container
	{
		std::deque<std::string>	args(av +1, av +ac);
		std::deque<int>		nums;

		try {
			secParseArgs(args);
			secConvertToInt(nums, args);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
	}

	return (0);
}
