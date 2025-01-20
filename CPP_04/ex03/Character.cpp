/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:50:14 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/20 20:45:03 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "grb.hpp"

Character::Character(void)
	: name("Unnamed"), buff(NULL)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	std::cout << "Default constructor for Character called" << std::endl;
}

Character::Character(const std::string &name)
	: name(name), buff(NULL)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	std::cout << "Parametrizeed constructor for Character called" << std::endl;
}

Character::Character(const Character &copy)
{
	clearMaterias(buff);
	buff = NULL;
	name = copy.name;
	for (int i = 0; i < 4; i++) {
		if (copy.slots[i])
		{
			this->slots[i] = copy.slots[i]->clone();
			storeMateria(&buff, newMateria(this->slots[i]));
		}
		else {
			this->slots[i] = NULL;
		}
	}
	std::cout << "Copy constructor for Character called" << std::endl;
}

Character::~Character(void)
{
	clearMaterias(buff);
	std::cout << "Destructor for Character called" << std::endl;
}

Character	&Character::operator=(const Character &copy)
{
	clearMaterias(buff);
	buff = NULL;
	name = copy.name;
	for (int i = 0; i < 4; i++) {
		if (copy.slots[i]) {
			this->slots[i] = copy.slots[i]->clone();
			storeMateria(&buff, newMateria(this->slots[i]));
		}
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
	if (!m)
		return ;
	storeMateria(&buff, newMateria(m));
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
