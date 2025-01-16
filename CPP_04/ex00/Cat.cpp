/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:11:38 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:17:19 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
	: Animal("Cat")
{
	std::cout << "Default constructor for Cat called" << std::endl;
}

Cat::Cat(const Cat &copy)
	: Animal(copy)
{
	type = copy.type;
	std::cout << "Copy constructor for Cat called" << std::endl;
}
Cat::~Cat(void)
{
	std::cout << "Destructor for Cat called" << std::endl;
}

Cat	&Cat::operator=(const Cat &copy)
{
	type = copy.type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meoww" << std::endl;
}
