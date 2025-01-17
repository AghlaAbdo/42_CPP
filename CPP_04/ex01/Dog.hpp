/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:19:34 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:56:06 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal {
private:
	Brain	*brain;
public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);
	Dog	&operator=(const Dog &copy);

	void	makeSound(void) const ;
	void	setBrainIdea(int index, std::string idea);
	std::string	getIdea(int index);
};

#endif