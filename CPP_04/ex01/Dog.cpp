/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:20:06 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/21 13:47:58 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void)
	: Animal("Dog")
{
	std::cout << "Default constructor for Dog called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const Dog &copy)
	: Animal(copy), brain(new Brain(*copy.brain))
{
	type = copy.type;
	std::cout << "Copy constructor for Dog called" << std::endl;
}
Dog::~Dog(void)
{
	delete brain;
	std::cout << "Destructor for Dog called" << std::endl;
}

Dog	&Dog::operator=(const Dog &copy)
{
	type = copy.type;
	delete brain;
	brain = new Brain(*copy.brain);
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Haw Haw" << std::endl;
}

void	Dog::setBrainIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100) {
		std::cout << "setBrainIdea(): index out of range" << std::endl;
		return ;
	}
	brain->setBrainIdea(index, idea);
}

std::string	Dog::getIdea(int index)
{
	if (index < 0 || index >= 100) {
		std::cout << "setBrainIdea(): index out of range" << std::endl;
		return ("");
	}
	return (brain->getIdea(index));
}
