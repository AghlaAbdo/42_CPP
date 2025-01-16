/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:04:44 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/16 22:16:39 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "type of j: " << j->getType() << " " << std::endl;
	std::cout << "type of i: " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "\nWrongAnimal test:\n" << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* a = new WrongCat();
	
	std::cout << "type of a: " << a->getType() << std::endl;
	a->makeSound();
	wrong->makeSound();

	delete wrong;
	delete a;

	std::cout << "\nMore tests:\n" << std::endl;

	const WrongCat* wCat = new WrongCat();
	const WrongAnimal wAnimal(*wCat);
	
	std::cout << "type of wCat: " << wCat->getType() << std::endl;
	std::cout << "type of wAnimal: " << wAnimal.getType() << std::endl;
	wCat->makeSound();
	wAnimal.makeSound();
	
	delete wCat;
	
	return 0;
}