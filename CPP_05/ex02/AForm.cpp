/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedon <thedon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:20:32 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/29 16:21:55 by thedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
	: _name("Unnamed"), _isSigned(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade <= 0 || execGrade <= 0)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy)
	: _name(copy.getName()), _isSigned(copy.getIsSigned()),
		_signGrade(copy.getSignGrade()), _execGrade(copy.getExecGrade()) {}

AForm::~AForm(void) {}

AForm	&AForm::operator=(const AForm &copy)
{
	_isSigned = copy.getIsSigned();
	return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::getIsSigned(void) const
{
	return (_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_execGrade);
}

void	AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (!_isSigned)
		_isSigned = true;
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "Form name: " << form.getName() << "\nis signed: " << form.getIsSigned()
		<< "\nSign grade: " << form.getSignGrade() << "\nExecute grade: " 
		<< form.getExecGrade() << std::endl;
	return (out);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Form::GradeTooLowException");
}

const char	*AForm::FormSignedException::what() const throw()
{
	return ("Form::FormSigendException");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form::FormNotSigendException");
}

// void	AForm::execute(Bureaucrat const &executor) const
// {
// 	std::cout << "AForm execute()" << std::endl;
// }
