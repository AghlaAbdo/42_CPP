#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
		return (0);
	}
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			av[i][j] = toupper(av[i][j]);
	}
	i = 0;
	while (av[++i])
		std::cout << av[i];
	std::cout << "\n";
	return (0);
}
