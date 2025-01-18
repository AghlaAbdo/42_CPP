/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:23:24 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:23:37 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
	: WrongAnimal("WrongCat")
{
	std::cout << "Default constructor for WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
	: WrongAnimal(copy)
{
	type = copy.type;
	std::cout << "Copy constructor for WrongCat called" << std::endl;
}
WrongCat::~WrongCat(void)
{
	std::cout << "Destructor for WrongCat called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &copy)
{
	type = copy.type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meoww" << std::endl;
}