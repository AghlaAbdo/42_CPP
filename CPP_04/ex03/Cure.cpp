/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:56:00 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/20 14:40:17 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
	: AMateria("cure")
{
	std::cout << "Default constructor for Cure called" << std::endl;
}

Cure::Cure(const Cure &copy)
	: AMateria(copy)
{
	std::cout << "Copy constructor for Cure called" << std::endl;
}

Cure	&Cure::operator=(const Cure &copy)
{
	(void)copy;
	std::cout << "Copy assignement constructor for Cure called" << std::endl;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "Destructor for Cure called" << std::endl;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
