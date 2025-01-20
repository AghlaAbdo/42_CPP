/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:56:05 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/19 08:01:09 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
	: AMateria("ice")
{
	std::cout << "Default constructor for Ice called" << std::endl;
}

Ice::Ice(const Ice &copy)
	: AMateria(copy)
{
	std::cout << "Copy constructor for Ice called" << std::endl;
}

Ice	&Ice::operator=(const Ice &copy)
{
	(void)copy;
	std::cout << "Copy assignement constructor for Ice called" << std::endl;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "Destructor for Ice called" << std::endl;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
