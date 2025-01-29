/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedon <thedon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:10:27 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/29 14:34:50 by thedon           ###   ########.fr       */
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

	class	GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};

	void	beSigned(const Bureaucrat &bur);
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif