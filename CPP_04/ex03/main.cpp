/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:13:09 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/19 11:23:09 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int	main(void)
{
	Ice m;
	ICharacter	*me = new Character("Me");
	// m.use(*me);
	me->equip(&m);
	me->use(0, *me);

	delete me;

	return (0);
}