/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaghla <aaghla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:09:41 by aaghla            #+#    #+#             */
/*   Updated: 2025/01/11 19:01:28 by aaghla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int   Fixed::nBits = 8;

Fixed::Fixed(void) : value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const newValue)
{
	// std::cout << "Int constructor called" << std::endl;
	value = newValue << nBits;
}

Fixed::Fixed(float const newValue)
{
	// std::cout << "Float constructor called" << std::endl;
	value = round(newValue * (1 << nBits));
}

Fixed &Fixed::operator=(Fixed const &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->value = src.value;
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void    Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float   Fixed::toFloat(void) const
{
	return ((float) this->value / (1 << nBits));
}

int Fixed::toInt(void) const
{
	return ((int)(value >> nBits));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}

//	Comparison operators
bool	Fixed::operator==(Fixed const &other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator>(Fixed const &other) const
{
	return (this->value > other.value);
}

bool	Fixed::operator<(Fixed const &other) const
{
	return (this->value < other.value);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (this->value <= other.value);
}

//	Arithmetic operators


Fixed	&Fixed::operator+(Fixed const &other)
{
	this->value += other.value;
	return (*this);
}

Fixed	&Fixed::operator-(Fixed const &other)
{
	this->value -= other.value;
	return (*this);
}

Fixed	&Fixed::operator*(Fixed const &other)
{
	this->value = (this->value * other.value) >> nBits;
	return (*this);
}

Fixed	&Fixed::operator/(Fixed const &other)
{
	if (other.value == 0) {
		std::cout << "Can't devide by 0 !!!" << std::endl;
		exit(1);
	}
	this->value = (this->value << nBits) / other.value;
	return (*this);
}

//	Increment & Decrement operators
Fixed	Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->value++;
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	this->value--;
	return (temp);
}

//	Overload functions
Fixed	&Fixed::min(Fixed &fst, Fixed &sec)
{
	if (sec < fst)
		return (fst);
	return (fst);
}

Fixed const	&Fixed::min(Fixed const &fst, Fixed const &sec)
{
	if (sec < fst)
		return (fst);
	return (fst);
}

Fixed	&Fixed::max(Fixed &fst, Fixed &sec)
{
	if (sec > fst)
		return (sec);
	return (fst);
}

Fixed const	&Fixed::max(Fixed const &fst, Fixed const &sec)
{
	if (sec > fst)
		return (sec);
	return (fst);
}
