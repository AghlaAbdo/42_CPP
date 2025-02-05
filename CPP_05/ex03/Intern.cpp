/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:05:19 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 16:27:44 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void){};

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern	&Intern::operator=(const Intern &copy) {
	*this = copy;
	return (*this);
}

Intern::~Intern(void) {}

AForm	*Intern::makeForm(std::string formName, std::string formTarget)
{
	AForm	*form = NULL;

	form = ShrubberyCreationForm::makeForm(form, formName, formTarget);
	form = RobotomyRequestForm::makeForm(form, formName, formTarget);
	form = PresidentialPardonForm::makeForm(form, formName, formTarget);
	
	if (!form)
		std::cout << "Intern couldn't create form: Invalid form name" << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	
	return (form);
}
