/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 11:36:05 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Skilipo");
	ScavTrap	scav("Biliko");
	
	
	clap.attack("Dahiya");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	for (int i = 0; i < 10; i++)
		clap.attack("Dahaya");

	clap.beRepaired(2);
	clap.takeDamage(8);
	clap.takeDamage(8);
	clap.takeDamage(8);

	std::cout << "\nTests for ScavTrap:\n" << std::endl;
	
	scav.attack("Dahiya");
	scav.takeDamage(10);
	scav.beRepaired(2);
	
	for (int i = 0; i < 40; i++)
		scav.attack("Dahiya");
	
	for (int i = 0; i < 10; i++)
		scav.beRepaired(2);
	
	for (int i = 0; i < 10; i++)
		scav.takeDamage(14);
	
	scav.beRepaired(10);
	scav.attack("Dahiya");
	scav.takeDamage(10);
	scav.guardGate();
	
	return (0);
}
