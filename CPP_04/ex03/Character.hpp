/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 01:38:48 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/21 11:38:13 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "grb.hpp"

class	Character : public ICharacter {
private:
	AMateria	*slots[4];
	std::string	name;
	t_grbMateria	*buff;

public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &copy);
	~Character(void);
	Character	&operator=(const Character &copy);

	std::string const &getName() const;
	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};

#endif