/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:54:21 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/01 20:00:30 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	newHarl;
	
	std::cout << "[ DEBUG ]\n";
	newHarl.complain("DEBUG");
	std::cout << "\n";
	std::cout << "[ INFO ]\n";
	newHarl.complain("INFO");
	std::cout << "\n";
	std::cout << "[ WARNING ]\n";
	newHarl.complain("WARNING");
	std::cout << "\n";
	std::cout << "[ ERROR ]\n";
	newHarl.complain("ERROR");
	std::cout << "\n";
	std::cout << "-----------\nCalling ERROR 10 times:\n";
	for (int i = 0; i < 10; i++)
		newHarl.complain("ERROR");
	return (0);
}