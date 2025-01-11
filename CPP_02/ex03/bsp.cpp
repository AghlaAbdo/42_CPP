/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:23:20 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/11 21:46:56 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ax = b.getX() - a.getX();
	Fixed	ay = b.getY() - a.getY();
	Fixed	bx = c.getX() - b.getX();
	Fixed	by = c.getY() - b.getY();
	Fixed	cx = a.getX() - c.getX();
	Fixed	cy = a.getY() - c.getY();
	
	Fixed cross1 = ax * (point.getY() - a.getY()) - ay * (point.getX() - a.getX());
	Fixed cross2 = bx * (point.getY() - b.getY()) - by * (point.getX() - b.getX());
	Fixed cross3 = cx * (point.getY() - c.getY()) - cy * (point.getX() - c.getX());
	
	if ((cross1 < 0 && cross2 < 0 && cross3 < 0) || (cross1 > 0 && cross2 > 0 && cross3 > 0))
		return (true);

	return (false);
}