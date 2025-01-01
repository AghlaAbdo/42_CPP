/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:54:21 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/01 17:31:05 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	newHarl;

	if (ac != 2) {
		std::cout << "invalid number of arguments\n";
		return (1);
	}
	newHarl.complain(av[1]);
	return (0);
}