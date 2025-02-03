/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:10:27 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/02 13:38:25 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	AForm {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	AForm(void);
	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &copy);
	~AForm(void);
	AForm	&operator=(const AForm &copy);

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
	class	FormSignedException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	class	FormNotSignedException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	

	void	beSigned(const Bureaucrat &bur);
	virtual void	execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);

#endif