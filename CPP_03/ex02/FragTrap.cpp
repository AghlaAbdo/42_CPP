/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:01:37 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 11:32:13 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	setName("Unnamed");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Default constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap(const std::string &newName)
{
	setName(newName);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "Constructor for FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
	: ClapTrap(copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "Copy constructor for FragTrap called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor for FragTrap called" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &copy)
{
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
	std::cout << "Copy Assignment operator for FragTrap called" << std::endl;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (getHitPoints() <= 0) {
		std::cout << "Health score is 0" << std::endl;
		return ;
	}
	if (!getEnergyPoints()) {
		std::cout << "No more energy to perform an action" << std::endl;
		return ;
	}
	std::cout << "Le Frog " << getName() << " Mdarb m3a " << target << ", causing  "
		<< getAttackDamage() << " points of damage" << std::endl;
	setEnergyPoints(getEnergyPoints() -1);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " is requesting a high five.." << std::endl;
}
