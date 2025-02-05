/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:00:23 by aaghla            #+#    #+#             */
/*   Updated: 2025/02/05 16:15:05 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class	Intern {
public:
	Intern(void);
	Intern(const Intern &copy);
	~Intern(void);
	Intern	&operator=(const Intern &copy);

	static AForm	*makeForm(std::string formName, std::string formTarget);
};

#endif