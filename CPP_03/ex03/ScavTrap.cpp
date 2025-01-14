/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:39:10 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 17:56:54 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	setName("Unnamed");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "Default constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName)
{
	setName(newName);
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "Constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
	: ClapTrap(copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "Copy constructor for ScavTrap called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor for " << getName() << " ScavTrap called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "Copy assignment operator for ScavTrap called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0) {
		std::cout << "Health score is 0" << std::endl;
		return ;
	}
	if (!getEnergyPoints()) {
		std::cout << "No more energy to perform an action" << std::endl;
		return ;
	}
	std::cout << "The hero " << getName() << " is attacking " << target << ", causing  "
		<< getAttackDamage() << " points of damage" << std::endl;
	setEnergyPoints(getEnergyPoints() -1);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode" << std::endl;
}

