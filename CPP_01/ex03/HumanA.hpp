/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:37:42 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 18:54:45 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA {
private:
	Weapon		weapon;
	std::string	name;

public:
	HumanA(std::string newName, Weapon newWeapon);
	void	attack(void);
};

#endif