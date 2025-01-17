/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:08:38 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:35:51 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

Brain::Brain(void)
{
	std::cout << "Default constructor for Brain called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	std::cout << "Copy constructor for Brain called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Destructor for Brain called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << "copy assignment for Brain called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = copy.ideas[i];
	return (*this);
}

void	Brain::setBrainIdea(int index, std::string idea)
{
	if (index < 0 || index >= 100) {
		std::cout << "setBrainIdea(): index out of range" << std::endl;
		return ;
	}
	ideas[index] = idea;
}

std::string	Brain::getIdea(int index)
{
	if (index < 0 || index >= 100) {
		std::cout << "setBrainIdea(): index out of range" << std::endl;
		return ("");
	}
	return (ideas[index]);
}
