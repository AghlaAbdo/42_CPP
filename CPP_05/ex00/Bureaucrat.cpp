/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:06:35 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/24 12:24:49 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	: _name("Unnamed"), _grade(150)
{
	std::cout << "Default constructor for Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int &grade)
	: _name(name)
{
	if (grade <= 0)
		throw "GradeTooHighException";
	else if (grade > 150)
		throw "GradeTooLowException";
	std::cout << "Parametrized constructor for Bureaucrat called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy.getName()), _grade(copy.getGrade())
{
	std::cout << "Copy constructor for Bureaucract called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy.getGrade();
	std::cout << "Copy assignment operator for Bureaucrat called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor for Bureaucrat called" << std::endl;
}

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::gradeInc(void)
{
	if (_grade - 1 <= 0)
		throw "GradeTooHighException";
	_grade--;
}

void	Bureaucrat::gradeDec(void)
{
	if (_grade + 1 > 150)
		throw "GradeTooLowException";
	_grade++;
}
