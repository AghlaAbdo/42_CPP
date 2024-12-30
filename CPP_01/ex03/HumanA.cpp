/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:41:40 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 18:55:10 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon newWeapon)
{
	name = newName;
	weapon = newWeapon;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType();
}