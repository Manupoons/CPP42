/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:36:50 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/26 11:41:35 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"


class Point {
	private:
		const Fixed x;
		const Fixed y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		const Fixed &getX() const;
		const Fixed &getY() const;

		bool operator==(const Point &other) const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif