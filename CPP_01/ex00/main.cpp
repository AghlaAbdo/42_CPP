/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:54:46 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 16:05:03 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::string	names1[] = {"Briz", "Freak", "Chreak", "Noom", "Biim"};
	std::string	names2[] = {"Varm", "Bilm", "Rown", "Skilipo", "Strike"};

	Zombie*	fstZombie = newZombie("Fillo");
	Zombie*	arrZombies[5];

	fstZombie->announce();
	randomChump("bl3id");
	delete fstZombie;
	
	for (int i = 0; i < 5; i++)
		randomChump(names1[i]);

	for (int i = 0; i < 5; i++)
		arrZombies[i] = newZombie(names2[i]);

	for (int i = 0; i < 5; i++)
		arrZombies[i]->announce();

	for (int i = 0; i < 5; i++)
		delete arrZombies[i];

	return (0);
}
