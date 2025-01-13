/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/13 13:57:51 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Skilipo");
	ClapTrap	b(a);
	
	a.attack("Dahiya");
	a.takeDamage(5);
	a.beRepaired(3);
	
	for (int i = 0; i < 10; i++)
		a.attack("Dahaya");

	a.beRepaired(2);
	a.takeDamage(8);
	a.takeDamage(8);
	a.takeDamage(8);
	
	std::cout << std::endl << "ClapTrap b: " << std::endl;

	b.beRepaired(2);
	b.attack("Dahiya");
	b.takeDamage(6);
	
	for (int i = 0; i < 10; i++)
		b.attack("Dahaya");
	b.takeDamage(4);
	b.beRepaired(10);
	b.takeDamage(4);
	b.takeDamage(5);

	return (0);
}
