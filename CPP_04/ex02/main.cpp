/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:04:44 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/18 17:41:53 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;

	std::cout << "\nMore tests:\n" << std::endl;
	
	const int arraySize = 4;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; ++i) {
		if (i < arraySize / 2) {
			animals[i] = new Dog();
		} else {
			animals[i] = new Cat();
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < arraySize; ++i) {
		animals[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i = 0; i < arraySize; ++i) {
		delete animals[i];
		std::cout << std::endl;
	}

	return (0);
}