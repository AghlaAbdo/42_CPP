/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:45:18 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 16:21:10 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class	ShrubberyCreationForm : public AForm {
private:
	std::string	_target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm	operator=(const ShrubberyCreationForm &copy);
	
	virtual void	execute(Bureaucrat const &executor) const;
	std::string		getTarget(void) const;

	static AForm	*makeForm(AForm *form, std::string formName, std::string formTarget);
};

#endif