/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:10:27 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/24 21:29:37 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Form {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	Form(void);
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &copy);
	~Form(void);
	Form	&operator=(const Form &copy);

	const std::string	&getName(void) const;
	bool		getIsSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;

	void	beSigned(const Bureaucrat &bur);
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif