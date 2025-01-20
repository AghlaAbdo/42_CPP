/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:55:12 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/20 11:55:43 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class	Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure &copy);
	~Cure(void);
	Cure	&operator=(const Cure &copy);
	AMateria*	clone() const;
	void		use(ICharacter &target);
};

#endif