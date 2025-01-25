/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:06:35 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/25 18:07:54 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void)
	: _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade <= 0)
		throw "Bureaucrat::GradeTooHighException";
	else if (grade > 150)
		throw "Bureaucrat::GradeTooLowException";
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	: _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

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
		throw "Bureaucrat::GradeTooHighException";
	_grade--;
}

void	Bureaucrat::gradeDec(void)
{
	if (_grade + 1 > 150)
		throw "Bureaucrat::GradeTooLowException";
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::signForm(const Form &form) const
{
	if (_grade > form.getSignGrade())
		std::cout << this->_name << " couldn't sign " << form.getName() << " because his grade is too low" << std::endl;
	else if (!form.getIsSigned()) {
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} else {
		std::cout << this->_name << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
	}
}
