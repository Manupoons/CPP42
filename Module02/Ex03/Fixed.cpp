/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:31:47 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/26 11:43:56 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : numValue(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	numValue = other.getRawBits();
}

Fixed::Fixed(const int &intVal) {
	// std::cout << "Int constructor called" << std::endl;
	numValue = intVal << fractionalBits;
}

Fixed::Fixed(const float &floatVal) {
	// std::cout << "Float constructor called" << std::endl;
	numValue = static_cast<int>(roundf(floatVal * (1 << fractionalBits)));
}

Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		numValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
	return numValue;
}

void Fixed::setRawBits(int const raw) {
	numValue = raw;
}

float Fixed::toFloat() const {
	return static_cast<float>(numValue) / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return numValue >> fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
	return numValue > other.numValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return numValue < other.numValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return numValue >= other.numValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return numValue <= other.numValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return numValue == other.numValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return numValue != other.numValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	numValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	numValue++;
	return temp;
}

Fixed &Fixed::operator--() {
	numValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	numValue--;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
