/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:55:59 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/06 15:06:57 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	bur("Jake", 10);
	Bureaucrat	bur2("Slave", 4);
	AForm	*shrub = new ShrubberyCreationForm("Home");
	AForm	*robot = new RobotomyRequestForm("Alice");
	AForm	*presd = new PresidentialPardonForm("Jane");
	
	std::cout << "-------- Trying to execute forms without being signed -------" << std::endl;
	try {
		shrub->execute(bur);
		robot->execute(bur);
		presd->execute(bur);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n-------- Trying to sign forms --------" << std::endl;
	try {
		shrub->beSigned(bur);
		robot->beSigned(bur);
		presd->beSigned(bur);
		std::cout << *shrub << std::endl;
		std::cout << *robot << std::endl;
		std::cout << *presd << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\n-------- Trying to execute forms after being signed -------" << std::endl;
	try {
		shrub->execute(bur);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		robot->execute(bur);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		presd->execute(bur);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	delete shrub;
	shrub = new ShrubberyCreationForm("Garden");
	shrub->beSigned(bur);

	std::cout << "\n--------- Trying to execute forms with Bureaucrat ---------" << std::endl;
	try {
		bur2.executeForm(*shrub);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		bur2.executeForm(*robot);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		bur2.executeForm(*presd);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	delete shrub;
	delete robot;
	delete presd;
	
	return (0);
}
