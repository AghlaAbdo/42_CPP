/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:48:08 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/18 18:55:27 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
	: type(type)
{
	std::cout << "Parametrized constructor for AMateria called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "Destructor for AMateria called" << std::endl;
}
