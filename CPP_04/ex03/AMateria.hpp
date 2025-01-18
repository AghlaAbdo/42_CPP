/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:39:09 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/18 18:49:08 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class	AMateria
{
protected:
	std::string	type;

public:
	AMateria(std::string const &type);
	virtual ~AMateria(void);

	std::string const	&getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter &target);
};
#endif