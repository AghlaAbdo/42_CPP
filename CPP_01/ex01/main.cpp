/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:54:46 by aaghla            #+#    #+#             */
/*   Updated: 2024/12/30 17:17:49 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	zombie1 = zombieHorde(1, "zombie 1");
	zombie1->announce();
	
	Zombie*	zombie2 = zombieHorde(10, "last Zombie");
	zombie2[9].announce();
	
	Zombie*	fstZombies = zombieHorde(5, "Skilipo");
	Zombie*	secZombies = zombieHorde(100, "Mindo");
	
	for (int i = 0; i < 5; i++)
		fstZombies[i].announce();

	for (int i = 0; i < 100; i++)
		secZombies[i].announce();
	
	delete[] zombie1;
	delete[] zombie2;
	delete[] fstZombies;
	delete[] secZombies;
	return (0);
}
