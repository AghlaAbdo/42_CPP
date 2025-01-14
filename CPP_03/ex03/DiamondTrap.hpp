/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:46:06 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 18:39:56 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string	name;

public:
	DiamondTrap(void);
	DiamondTrap(const std::string &newName);
	DiamondTrap(const DiamondTrap &copy);
	~DiamondTrap(void);
	DiamondTrap	&operator=(const DiamondTrap &copy);
	
	void	attack(const std::string &target);
	void	whoAmI(void);
};

#endif