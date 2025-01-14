/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:56:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 18:55:02 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diam("Skilopo");

	diam.attack("Dahiya");
	diam.takeDamage(10);
	diam.beRepaired(5);
	
	diam.guardGate();
	diam.highFivesGuys();
	diam.whoAmI();
	
	for (int i = 0; i < 25; i++)
		diam.attack("Dahaya");
	
	for (int i = 0; i < 25; i++)
		diam.beRepaired(2);
	
	for (int i = 0; i < 10; i++)
		diam.takeDamage(16);

	diam.attack("Dahiya");
	diam.beRepaired(10);
	diam.takeDamage(10);
	diam.whoAmI();
	
	return (0);
}
