/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thedon <thedon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:31:17 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/29 14:33:06 by thedon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPPP
#define BUREAUCRAT_HPPP

#include <iostream>

class	Form;

class	Bureaucrat {
private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat(void);
	Bureaucrat	&operator=(const Bureaucrat &copy);

	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void		gradeInc(void);
	void		gradeDec(void);

	class	GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception {
	public:
		virtual const char	*what() const throw();
	};
	
	void	signForm(Form &form);
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur);

#endif
