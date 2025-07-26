/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:36:53 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/26 11:43:35 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
	// std::cout << "Default Point constructor called" << std::endl;
}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {
	// std::cout << "Parameterized Point constructor called" << std::endl;
}

Point::Point(const Point &other) : x(other.x), y(other.y) {
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
	// std::cout << "Assignment operator called (noop due to const members)" << std::endl;
	(void)other;
	return *this;
}

Point::~Point() {
	// std::cout << "Point destructor called" << std::endl;
}

const Fixed &Point::getX() const {
	return x;
}

const Fixed &Point::getY() const {
	return y;
}

bool Point::operator==(const Point &other) const {
	return (this->x == other.x) && (this->y == other.y);
}

std::ostream &operator<<(std::ostream &out, const Point &point) {
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return out;
}
