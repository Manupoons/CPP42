/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:26:36 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 11:59:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _value;
		static const int _bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int intVal);
		Fixed(const float floatVal);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed& bigger) const;
		bool operator<(const Fixed& smaller) const;
		bool operator>=(const Fixed& bigger_equal) const;
		bool operator<=(const Fixed& smaller_equal) const;
		bool operator==(const Fixed& equal) const;
		bool operator!=(const Fixed& not_equal) const;

		Fixed operator+(const Fixed& plus) const;
		Fixed operator-(const Fixed& minus) const;
		Fixed operator*(const Fixed& multiply) const;
		Fixed operator/(const Fixed& divide) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif