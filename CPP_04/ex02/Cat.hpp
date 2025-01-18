/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:07:58 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:56:11 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal {
private:
	Brain	*brain;
public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);
	Cat	&operator=(const Cat &copy);

	void	makeSound(void) const ;
	void	setBrainIdea(int index, std::string idea);
	std::string	getIdea(int index);
};

#endif