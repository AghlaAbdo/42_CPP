/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 12:17:50 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/19 12:38:55 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class	MateriaSource : public IMateriaSource {
private:
	AMateria	*slots[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &copy);
	~MateriaSource(void);
	MateriaSource &operator=(const MateriaSource &copy);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);
};

#endif