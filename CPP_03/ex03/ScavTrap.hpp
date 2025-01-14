/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:34:51 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 15:40:37 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string newName);
	~ScavTrap(void);
	ScavTrap	&operator=(const ScavTrap &copy);

	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif