/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedon <thedon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:20:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/29 16:21:55 by thedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aform.hpp"
#include "Bureaucrat.hpp"

Aform::Aform(void)
	: _name("Unnamed"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Aform::Aform(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade <= 0 || execGrade <= 0)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Aform::Aform(const Aform &copy)
	: _name(copy.getName()), _isSigned(copy.getIsSigned()),
		_signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {}

Aform::~Aform(void) {}

Aform	&Aform::operator=(const Aform &copy)
{
	_isSigned = copy.getIsSigned();
	return (*this);
}

const std::string	&Aform::getName(void) const
{
	return (_name);
}

bool	Aform::getIsSigned(void) const
{
	return (_isSigned);
}

int	Aform::getSignGrade(void) const
{
	return (_signGrade);
}

int	Aform::getExecGrade(void) const
{
	return (_execGrade);
}

void	Aform::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _signGrade)
		// throw 
		throw GradeTooLowException();
	if (!_isSigned)
		_isSigned = true;
}

std::ostream	&operator<<(std::ostream &out, const Aform &form)
{
	out << "Form name: " << form.getName() << "\nis signed: " << form.getIsSigned()
		<< "\nSign grade: " << form.getSignGrade() << "\nExecute grade: " 
		<< form.getExecGrade() << std::endl;
	return (out);
}

const char	*Aform::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*Aform::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}
