/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:04:44 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/17 21:50:31 by aaghla           ###   ########.fr       */
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
	
	const size_t arraySize = 4;
    Animal* animals[arraySize];

    for (size_t i = 0; i < arraySize; ++i) {
        if (i < arraySize / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
		std::cout << std::endl;
    }

    for (size_t i = 0; i < arraySize; ++i) {
        animals[i]->makeSound();
    }

    for (size_t i = 0; i < arraySize; ++i) {
        delete animals[i];
		std::cout << std::endl;
    }

	std::cout << "\nCat deep copy test:\n" << std::endl;

	Cat *ca = new Cat();
	ca->setBrainIdea(0, "No idea");
	std::cout << std::endl;
	Cat	*cb = new Cat(*ca);
	
	std::cout << "\nca idea: " << ca->getIdea(0) << std::endl;
	std::cout << "cb idea: " << cb->getIdea(0)<< std::endl;
	ca->setBrainIdea(0, "Idea Removed");
	std::cout << "\nca idea: " << ca->getIdea(0) << std::endl;
	std::cout << "cb idea: " << cb->getIdea(0) << std::endl;

	std::cout << std::endl;
	
	std::cout << ca->getType() << "\n" << cb->getType() << std::endl;
	
	delete ca;
	std::cout << std::endl;
	delete cb;
	
	std::cout << "\nDog deep copy test:\n" << std::endl;

	Dog *da = new Dog();
	da->setBrainIdea(0, "No idea");
	std::cout << std::endl;
	Dog	*db = new Dog(*da);
	
	std::cout << "\nda idea: " << da->getIdea(0) << std::endl;
	std::cout << "db idea: " << db->getIdea(0)<< std::endl;
	da->setBrainIdea(0, "Idea Removed");
	std::cout << "\nda idea: " << da->getIdea(0) << std::endl;
	std::cout << "db idea: " << db->getIdea(0) << std::endl;

	std::cout << std::endl;
	
	std::cout << da->getType() << "\n" << db->getType() << std::endl;
	
	delete da;
	std::cout << std::endl;
	delete db;

	return (0);
}