/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                           :+:      :+:    :+:   */
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

class	Aform {
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	Aform(void);
	Aform(std::string name, int signGrade, int execGrade);
	Aform(const Aform &copy);
	~Aform(void);
	Aform	&operator=(const Aform &copy);

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
	virtual void	execute(Bureaucrat const &executor) = 0;
};

std::ostream	&operator<<(std::ostream &out, const Aform &Aform);

#endif