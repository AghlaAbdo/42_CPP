/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:28 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/11 19:01:01 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(0), y(0) {}

Point::Point(float const setX, float const setY) : x(setX), y(setY) {}

Point::Point(Point const &copy)
{
	*this = copy;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

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
		this->x = src.x;
		this->y = src.y;
	}
	return (*this);
}
