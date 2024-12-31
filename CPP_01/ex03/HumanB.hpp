/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:42:31 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/31 15:08:54 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {
private:
	std::string	name;

public:
	Weapon*		weapon;
	HumanB(std::string newName);
	void	attack(void);
	void	setWeapon(Weapon& newWeapon);
};

#endif