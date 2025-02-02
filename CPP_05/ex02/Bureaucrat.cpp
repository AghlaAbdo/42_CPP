/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:06:35 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/02 13:39:28 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Aform.hpp"

Bureaucrat::Bureaucrat(void)
	: _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name)
{
	if (grade <= 0)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::gradeDec(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

void	Bureaucrat::signForm(Aform &form)
{
	if (_grade > form.getSignGrade())
		std::cout << _name << " couldn’t sign " << form.getName()
			<< " because his grade is too low." << std::endl;
	else if (_grade <= form.getSignGrade() && form.getIsSigned())
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because the form is already signed." << std::endl;
	else {
		try {
			form.beSigned(*this);
			std::cout << _name << " signed " << form.getName() << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what();
		}
	}
}
