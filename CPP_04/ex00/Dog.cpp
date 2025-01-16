/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:20:06 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:03:12 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
	: Animal("Dog")
{
	std::cout << "Default constructor for Dog called" << std::endl;
}

Dog::Dog(const Dog &copy)
	: Animal(copy)
{
	type = copy.type;
	std::cout << "Copy constructor for Dog called" << std::endl;
}
Dog::~Dog(void)
{
	std::cout << "Destructor for Dog called" << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	type = copy.type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Haw Haw" << std::endl;
}
