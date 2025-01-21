/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:13:09 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/21 13:21:17 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "\nMore tests: \n" << std::endl;

	Character	*div = new Character("Dive");
	Character	*bill = new Character("Bill");
	MateriaSource	mtr;
	
	mtr.learnMateria(new Ice());
	mtr.learnMateria(mtr.createMateria("ice"));

	div->equip(mtr.createMateria("cure"));
	div->equip(mtr.createMateria("ice"));
	div->equip(new Cure());
	
	std::cout << "Dive:" << std::endl;
	div->use(0, *div);
	div->use(1, *div);
	*bill = *div;
	delete div;
	
	std::cout << "Bill:" << std::endl;
	bill->use(0, *bill);
	bill->use(1, *bill);
	
	delete bill;
	
	return 0;
}