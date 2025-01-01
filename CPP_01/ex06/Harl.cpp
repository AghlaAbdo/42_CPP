/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:49:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/01 20:04:30 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-\
pickle-specialketchup burger.\nI really do!\n";
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n\
You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\n\
I’ve been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*funcArray[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		i;
	
	i = 0;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
			break ;
	}
	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]\n";
			(this->*funcArray[0])();
			std::cout << "\n";
		case 1:
			std::cout << "[ INFO ]\n";
			(this->*funcArray[1])();
			std::cout << "\n";
		case 2:
			std::cout << "[ WARNING ]\n";
			(this->*funcArray[2])();
			std::cout << "\n";
		case 3:
			std::cout << "[ ERROR ]\n";
			(this->*funcArray[3])();
			std::cout << "\n";
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
