/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:28 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/12 14:33:54 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(float const setX, float const setY) : x(setX), y(setY) {}

Point::Point(Point const &copy) : x(copy.getX()), y(copy.getY()) {}

Point::~Point(void) {}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}

Point	&Point::operator=(Point const &src)
{
	if (this != &src)
	{
		std::cout << "Can't reassigne const members !!" << std::endl;
	}
	return (*this);
}
