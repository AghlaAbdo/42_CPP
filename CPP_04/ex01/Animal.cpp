/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:58:18 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 22:14:05 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
	: type("Unknown")
{
	std::cout << "Default constructor for Animal called" << std::endl;
}

Animal::Animal(const std::string &setType)
	: type(setType)
{
	std::cout << "Parametrized constructor for Animal called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "Copy constructor for Animal called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Destructor for Animal called" << std::endl;
}

Animal	&Animal::operator=(const Animal &copy)
{
	this->type = copy.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	return ;
}

const std::string	&Animal::getType(void) const
{
	return (type);
}
