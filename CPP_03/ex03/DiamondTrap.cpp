/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:00:05 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/15 10:20:30 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: name("Unnamed")
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "Default constructor fo DiamondTrap Called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &newName)
	: FragTrap(newName + "_clap_name"), name(newName)
{
	setHitPoints(FragTrap::getHitPoints());
	setEnergyPoints(ScavTrap::getEnergyPoints());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "Constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy)
	: ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "Copy constructor for DiamondTrap called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor for " << name << " DiamondTrap called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
