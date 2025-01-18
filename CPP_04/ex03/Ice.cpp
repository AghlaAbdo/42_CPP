/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:56:05 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/18 19:10:57 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
	: AMateria("ice")
{
	std::cout << "Default constructor for Ice called" << std::endl;
}

Ice::Ice(const Ice &copy)
	: AMateria(copy)
{

}
