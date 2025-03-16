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
		std::vector<int>	nums;

		try {
			fstParseArgs(args);
			fstConvertToInt(nums, args);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return (1);
		}
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
