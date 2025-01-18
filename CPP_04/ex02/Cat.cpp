/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:11:38 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:35:46 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
	: Animal("Cat")
{
	std::cout << "Default constructor for Cat called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat &copy)
	: Animal(copy), brain(new Brain(*copy.brain))
{
	type = copy.type;
	std::cout << "Copy constructor for Cat called" << std::endl;
}
Cat::~Cat(void)
{
	delete brain;
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

void	Cat::setBrainIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100) {
		std::cout << "setBrainIdea(): index out of range" << std::endl;
		return ;
	}
	brain->setBrainIdea(index, idea);
}

std::string	Cat::getIdea(int index)
{
	if (index < 0 || index >= 100) {
		std::cout << "setBrainIdea(): index out of range" << std::endl;
		return ("");
	}
	return (brain->getIdea(index));
}
