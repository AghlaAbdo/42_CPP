/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:54:21 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/01 16:56:01 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	newHarl;
	
	newHarl.complain("DEBUG");
	newHarl.complain("INFO");
	newHarl.complain("WARNING");
	newHarl.complain("ERROR");
	std::cout << "-----------\nCalling error 10 times:\n";
	for (int i = 0; i < 10; i++)
		newHarl.complain("ERROR");
	return (0);
}