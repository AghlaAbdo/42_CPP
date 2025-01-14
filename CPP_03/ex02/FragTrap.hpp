/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:58:19 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/14 11:37:53 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap:public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string &newName);
	FragTrap(const FragTrap &copy);
	~FragTrap(void);
	FragTrap	&operator=(const FragTrap &copy);

	void	attack(const std::string &target);
	void	highFivesGuys(void);
};

#endif
