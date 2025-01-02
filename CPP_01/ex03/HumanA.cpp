/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:41:40 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/02 08:56:36 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon)
	: weapon(newWeapon), name(newName) {}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << "\n";
}