#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Requires arguments to sort" << std::endl;
		return (1);
	}

	// std::vector container
	{
		std::vector<std::string>	args(av + 1, av + ac);
		std::vector<std::pair<int, int> >	nums;

		try {
			fstParseArgs(args);
			fstConvertToInt(nums, args);
			fstSortNums(nums);
			
			// std::cout << "----- Befor: -----" << std::endl;
			// std::vector<std::pair<int, int> >::iterator	it;
			// for (it = nums.begin(); it != nums.end(); it++) {
			// 	std::cout << it->first << " " << it->second << " |" << std::endl;
			// }
			fstSortPairs(nums);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
		// std::cout << "\n----- After: -----" << std::endl;
		std::vector<std::pair<int, int> >::iterator	it;
		// for (it = nums.begin(); it != nums.end(); it++) {
		// 	std::cout << it->first << " " << it->second << " |" << std::endl;
		// }
		// std::cout << std::endl;
		
		// std::vector<std::pair<int, int> >::iterator	it2;
		// for (it = nums.begin(); it != nums.end(); it++) {
		// 	for (it2 = it; it2 != nums.end(); it2++) {
		// 		if (it->first > it2->first) {
		// 			std::cout << "Not Sorted" << std::endl;
		// 			return (1);

		// 		}
		// 	}
		// }
		// std::cout << "Sorted" << std::endl;
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
