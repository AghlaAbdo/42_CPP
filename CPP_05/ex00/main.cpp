/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:55:59 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/24 16:01:58 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat	bur("Bill", -50);
	}
	catch (char const *e) {
		std::cout << e << std::endl;
	}

	try {
		Bureaucrat	bur("Bill", 151);
	}
	catch (char const *e) {
		std::cout << e << std::endl;
	}
	std::cout << std::endl;

	Bureaucrat	bur("Dive", 1);
	Bureaucrat	bur2("Jake", 150);
	std::cout << bur;
	std::cout << bur2 << std::endl;
	
	try {
		bur.gradeInc();
	}
	catch (char const *e) {
		std::cout << e << std::endl;
	}

	try {
		bur2.gradeDec();
	}
	catch (char const *e) {
		std::cout << e << std::endl;
	}
	
	std::cout << "\n" << bur;
	std::cout << bur2;

	bur.gradeDec();
	bur2.gradeInc();

	std::cout << "\n" << bur;
	std::cout << bur2;
	
	return (0);
}
