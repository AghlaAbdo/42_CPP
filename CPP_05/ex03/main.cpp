/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:55:59 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 19:03:54 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern intern;
	AForm	*form;
	Bureaucrat bur("Dive", 20);
	
	form = intern.makeForm("robotomy request", "Jhone");
	
	std::cout << "\n----------- Try to execute form without being sigend -----------" << std::endl;
	try {
		form->execute(bur);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n---------- Try to sign form ------------" << std::endl;
	try {
		bur.signForm(*form);
		std::cout << "is form sigend: " << form->getIsSigned() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n---------- Try to execute after being signed ------------" << std::endl;
	try {
		form->execute(bur);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete	form;

	std::cout << "\n------------ intern create Shrubbery Creation form -----------" << std::endl;
	form = intern.makeForm("shrubbery creation", "Jake");
	try {
		form->beSigned(bur);
		form->execute(bur);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete form;

	std::cout << "\n-----------intern create Presidential Pardon form -----------" << std::endl;
	form = intern.makeForm("presidential pardon", "Jane");
	try {
		form->beSigned(bur);
		form->execute(bur);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete form;

	std::cout << "\n------- Intern creates invalid forms ----------" << std::endl;
	form = intern.makeForm("invalid name", "Dive");
	form = intern.makeForm("form", "Dive");
	
	
	return (0);
}
