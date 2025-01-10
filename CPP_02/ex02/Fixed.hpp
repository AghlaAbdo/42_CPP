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
	Fixed(Fixed const &copy);
	~Fixed(void);

	Fixed(const int newValue);
	Fixed(const float newValue);
	
	Fixed	&operator=(Fixed const &src);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	//	Comparison operators
	bool	operator==(Fixed const &other) const;
	bool	operator>(Fixed const &other) const;
	bool	operator<(Fixed const &other) const;
	bool	operator>=(Fixed const &other) const;
	bool	operator<=(Fixed const &other) const;

	//	Arithmetic operators
	Fixed	&operator+(Fixed const &other);
	Fixed	&operator-(Fixed const &other);
	Fixed	&operator*(Fixed const &other);
	Fixed	&operator/(Fixed const &other);

	//	Increment & Decrement operators
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	//	Overload functions
	static Fixed	&min(Fixed &fst, Fixed &sec);
	static Fixed const	&min(Fixed const &fst, Fixed const &sec);
	static Fixed	&max(Fixed &fst, Fixed &sec);
	static Fixed const	&max(Fixed const &fst, Fixed const &sec);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif