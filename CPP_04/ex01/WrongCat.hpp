/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:19:18 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:24:32 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat &copy);
	~WrongCat(void);
	WrongCat	&operator=(const WrongCat &copy);

	void	makeSound(void) const;
};

#endif