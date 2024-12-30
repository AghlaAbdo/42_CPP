/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:30:02 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 17:07:57 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <vector>

class	Zombie {
private:
	std::string	name;

public:
	Zombie(void);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string zombieName);
};

Zombie*	zombieHorde( int N, std::string name );

#endif