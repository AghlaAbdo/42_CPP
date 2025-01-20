/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:21:22 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/19 12:27:27 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "Default constructor for MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	std::cout << "Copy constructor for MateriaSource called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "Destructor for MateriaSource called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &copy)
{
	std::cout << "Copy assigement for MateriaSource called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	
}
