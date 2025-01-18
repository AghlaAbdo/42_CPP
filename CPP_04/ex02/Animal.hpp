/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:54:09 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/18 14:25:42 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class	Animal {
protected:
	std::string	type;

public:
	Animal(const std::string &setType);
	Animal(const Animal &copy);
	virtual ~Animal(void);
	Animal	&operator=(const Animal &copy);

	virtual void		makeSound(void) const = 0;
	const std::string	&getType(void) const;
};

#endif