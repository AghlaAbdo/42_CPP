/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:25:14 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 18:53:35 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class   Weapon {
private:
	std::string type;

public:
	Weapon(std::string newType);
	const std::string&	getType(void);
	void	setType(std::string newType);
};

#endif