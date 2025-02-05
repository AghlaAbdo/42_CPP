/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:44:16 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 16:14:43 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("Unnamed") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy), _target(copy.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm	RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	_target = copy.getTarget();
	return (*this);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	
	std::cout << "drilling noises... drrrrrrrrr" << std::endl;
	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout <<  _target << " robotomy failed" << std::endl;

}

AForm	*RobotomyRequestForm::makeForm(AForm *form, std::string type, std::string target)
{
	if (!form && type == "robotomy request")
		return (new RobotomyRequestForm(target));
	return (form);
}
