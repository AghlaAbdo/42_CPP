#include <iostream>

using std::cout;
using std::endl;
using std::toupper;

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
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
		cout << av[i];
	cout << endl;
	return (0);
}
