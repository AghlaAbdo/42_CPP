/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:43:08 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 16:17:30 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	RobotomyRequestForm : public AForm {
private:
	std::string	_target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	operator=(const RobotomyRequestForm &copy);
	
	virtual void	execute(Bureaucrat const &executor) const;
	std::string		getTarget(void) const;

	static AForm	*makeForm(AForm *form, std::string type, std::string target);
};

#endif