/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:20:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/25 18:08:23 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
	: _name("Unnamed"), _isSigned(false), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade <= 0 || execGrade <= 0)
		throw "Form::GradeTooHighException";
	else if (signGrade > 150 || execGrade > 150)
		throw "Form::GradeTooLowException";
}

Form::Form(const Form &copy)
	: _name(copy.getName()), _isSigned(copy.getIsSigned()),
		_signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {}

Form::~Form(void) {}

Form	&Form::operator=(const Form &copy)
{
	_isSigned = copy.getIsSigned();
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

bool	Form::getIsSigned(void) const
{
	return (_isSigned);
}

int	Form::getSignGrade(void) const
{
	return (_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat &bur)
{
	bur.signForm(*this);
	if (bur.getGrade() > _signGrade)
		throw "Form::GradeTooLowException";
	if (!_isSigned)
		_isSigned = true;
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form name: " << form.getName() << "\nis signed: " << form.getIsSigned()
		<< "\nSign grade: " << form.getSignGrade() << "\nExecute grade: " 
		<< form.getExecGrade() << std::endl;
	return (out);
}
