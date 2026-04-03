/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:31:47 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 12:16:37 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& assign)
{
	if (this != &assign)
		_value = assign.getRawBits();
	return *this;
}

Fixed::Fixed(const int intVal)
{
	_value = intVal * (1 << _bits);
}

Fixed::Fixed(const float floatVal)
{
	_value = roundf(floatVal * (1 << _bits));
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat() const
{
	return (float)(_value) / (1 << _bits);
}

int Fixed::toInt() const
{
	return roundf(_value / (1 << _bits));
}

bool Fixed::operator>(const Fixed& bigger) const
{
	return _value > bigger._value;
}

bool Fixed::operator<(const Fixed& smaller) const
{
	return _value < smaller._value;
}

bool Fixed::operator>=(const Fixed& bigger_equal) const
{
	return _value >= bigger_equal._value;
}

bool Fixed::operator<=(const Fixed& smaller_equal) const
{
	return _value <= smaller_equal._value;
}

bool Fixed::operator==(const Fixed& equal) const
{
	return _value == equal._value;
}

bool Fixed::operator!=(const Fixed& not_equal) const
{
	return _value != not_equal._value;
}

Fixed Fixed::operator+(const Fixed& plus) const
{
	Fixed res;
	res._value = this->getRawBits() + plus.getRawBits();
	return res;
}

Fixed Fixed::operator-(const Fixed& minus) const
{
	Fixed res;
	res._value = this->getRawBits() - minus.getRawBits();
	return res;
}

Fixed Fixed::operator*(const Fixed& multiply) const
{
	Fixed res(this->toFloat() * multiply.toFloat());
	return res;
}

Fixed Fixed::operator/(const Fixed& divide) const
{
	Fixed res(this->toFloat() / divide.toFloat());
	return res;
}

Fixed& Fixed::operator++()
{
	_value ++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_value++;
	return temp;
}

Fixed& Fixed::operator--()
{
	_value --;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_value--;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
