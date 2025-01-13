/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:07:59 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/13 13:59:37 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: name("Unnamed"), hitPoints(10), energyPoints(10), attakDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
	: name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints),
		attakDamage(copy.attakDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string setName)
	: name(setName), hitPoints(10), energyPoints(10), attakDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attakDamage = copy.attakDamage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0) {
		std::cout << "Health score is 0" << std::endl;
		return ;
	}
	if (!this->energyPoints) {
		std::cout << "No more energy to perform an action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing  "
		<< this->attakDamage << " points of damage" << std::endl;
	this->energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0) {
		std::cout << "Health score is 0" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount
		<< " points of damage" << std::endl;
	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0) {
		std::cout << "Health score is 0" << std::endl;
		return ;
	}
	if (!this->energyPoints) {
		std::cout << "No more energy to perform an action" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " gained " << amount
		<< " points of hit points after repairing" << std::endl;
	this->hitPoints += amount;
	this->energyPoints--;
}
