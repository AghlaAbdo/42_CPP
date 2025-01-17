/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:07:58 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:57:08 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat &copy);
	~Cat(void);
	Cat	&operator=(const Cat &copy);

	void	makeSound(void) const;
};

#endif