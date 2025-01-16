/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:19:34 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:02:53 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog &copy);
	~Dog(void);
	Dog	&operator=(const Dog &copy);

	void	makeSound(void) const override;
};

#endif