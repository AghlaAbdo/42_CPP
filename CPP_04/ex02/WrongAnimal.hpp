/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 20:20:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 20:23:56 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal {
protected:
	std::string	type;

public:
	WrongAnimal(void);
	WrongAnimal(const std::string &setType);
	WrongAnimal(const WrongAnimal &copy);
	virtual ~WrongAnimal(void);
	WrongAnimal	&operator=(const WrongAnimal &copy);

	void		makeSound(void) const;
	const std::string	&getType(void) const;
};

#endif