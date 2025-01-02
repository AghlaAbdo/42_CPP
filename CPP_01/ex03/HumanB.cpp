/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:43:20 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/02 08:48:12 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
	: weapon(nullptr), name(newName) {}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their ";
	if (weapon)
		std::cout << weapon->getType() << "\n";
	else
		std::cout << "hands\n";
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	weapon = &newWeapon;
}