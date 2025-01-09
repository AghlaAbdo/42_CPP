/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:39:03 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/07 15:43:48 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
private:
	int				value;
	static const int nBits;
public:
	Fixed(void);
	Fixed(const Fixed &copy);
	~Fixed(void);

	Fixed(const int newValue);
	Fixed(const float newValue);
	
	Fixed	&operator=(const Fixed &src);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);

#endif