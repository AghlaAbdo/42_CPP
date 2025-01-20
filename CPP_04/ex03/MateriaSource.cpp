/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:21:22 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/20 20:44:33 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "grb.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		slots[i] = NULL;
	std::cout << "Default constructor for MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	clearMaterias(buff);
	buff = NULL;
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
	std::cout << "Copy constructor for MateriaSource called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	clearMaterias(buff);
	std::cout << "Destructor for MateriaSource called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	clearMaterias(buff);
	buff = NULL;
	for (int i = 0; i < 4; i++) {
		if (copy.slots[i]) {
			this->slots[i] = copy.slots[i]->clone();
			storeMateria(&buff, newMateria(this->slots[i]));
		}
		else
			this->slots[i] = NULL;
	}
	std::cout << "Copy assigement for MateriaSource called" << std::endl;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return ;
	storeMateria(&buff, newMateria(materia));
	for (int i = 0; i < 4; i++) {
		if (!slots[i]) {
			slots[i] = materia;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++) {
		if (slots[i]) {
			if (!slots[i]->getType().compare(type))
				return (slots[i]->clone());
		}
	}
	return (0);
}
