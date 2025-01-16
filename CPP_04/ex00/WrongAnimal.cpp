/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:20:17 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:21:29 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	: type("Unknown")
{
	std::cout << "Default constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &setType)
	: type(setType)
{
	std::cout << "Parametrized constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	this->type = copy.type;
	std::cout << "Copy constructor for WrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor for WrongAnimal called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy)
{
	this->type = copy.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Default WrongAnimal sound" << std::endl;
	return ;
}

const std::string	&WrongAnimal::getType(void) const
{
	return (type);
}