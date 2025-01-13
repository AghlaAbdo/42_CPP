/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:36:09 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/13 12:51:24 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap {
private:
	std::string	name;
	int			hitPoints;
	int			energyPoints;
	int			attakDamage;

public:
	ClapTrap(void);
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string setName);
	~ClapTrap(void);
	ClapTrap	&operator=(const ClapTrap &copy);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif