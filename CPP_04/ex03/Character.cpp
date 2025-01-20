/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:50:14 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/19 11:21:57 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
	: name("Unnamed")
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	std::cout << "Default constructor for Character called" << std::endl;
}

Character::Character(const std::string &name)
	: name(name)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	std::cout << "Parametrizeed constructor for Character called" << std::endl;
}

Character::Character(const Character &copy)
{
	name = copy.name;
	for (int i = 0; i < 4; i++) {
		if (copy.slots[i])
			this->slots[i] = copy.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
	std::cout << "Copy constructor for Character called" << std::endl;
}

Character::~Character(void)
{
	std::cout << "Destructor for Character called" << std::endl;
}

Character	&Character::operator=(const Character &copy)
{
	name = copy.name;
	for (int i = 0; i < 4; i++)
		delete slots[i];
	for (int i = 0; i < 4; i++) {
		if (copy.slots[i])
			this->slots[i] = copy.slots[i]->clone();
		else
			this->slots[i] = NULL;
	}
	std::cout << "Copy assignement for Character called" << std::endl;
	return (*this);
}

std::string const	&Character::getName() const
{
	return (name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++) {
		if (!slots[i]) {
			slots[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (slots[idx])
		slots[idx]->use(target); 
}
