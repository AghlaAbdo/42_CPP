/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:31:17 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/24 15:11:30 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPPP
#define BUREAUCRAT_HPPP

#include <iostream>

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
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bur);

#endif