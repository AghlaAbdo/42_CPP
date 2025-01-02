/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:42:31 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/02 08:46:17 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {
private:
	Weapon*		weapon;
	std::string	name;

public:
	HumanB(std::string newName);
	void	attack(void);
	void	setWeapon(Weapon& newWeapon);
};

#endif