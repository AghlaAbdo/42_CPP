/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:27:27 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/03 11:12:10 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PresidentialPardonForm", 25, 5), _target("Unnamed") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy), _target(copy.getTarget()) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm	PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	_target = copy.getTarget();
	return (*this);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();

	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}