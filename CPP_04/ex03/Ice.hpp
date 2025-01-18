/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:43:50 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/18 18:47:41 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice &copy);
	~Ice(void);
	Ice	&operator=(const Ice &copy);
	AMateria*	clone() const;
	void		use(ICharacter &target);
};

#endif