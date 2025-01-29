/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedon <thedon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:55:59 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/29 16:40:26 by thedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	bur("Bill", -50);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat	bur("Bill", 151);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat	bur("Dive", 1);
	Bureaucrat	bur2("Jake", 150);
	std::cout << bur;
	std::cout << bur2 << std::endl;
	
	try {
		bur.gradeInc();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		bur2.gradeDec();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n" << bur;
	std::cout << bur2;

	bur.gradeDec();
	bur2.gradeInc();

	std::cout << "\n" << bur;
	std::cout << bur2;
	
	return (0);
}
