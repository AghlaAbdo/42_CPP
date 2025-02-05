/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:21:11 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 16:21:44 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {
private:
	std::string	_target;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);
	PresidentialPardonForm	operator=(const PresidentialPardonForm &copy);
	
	virtual void	execute(Bureaucrat const &executor) const;
	std::string		getTarget(void) const;

	static AForm	*makeForm(AForm *form, std::string formName, std::string formTarget);
};

#endif