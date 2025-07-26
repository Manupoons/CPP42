/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:36:24 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/26 11:41:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed area(Point const &a, Point const &b, Point const &c) {
	Fixed term1 = a.getX() * (b.getY() - c.getY());
	Fixed term2 = b.getX() * (c.getY() - a.getY());
	Fixed term3 = c.getX() * (a.getY() - b.getY());
	Fixed result = (term1 + term2 + term3) / Fixed(2);
	return result < 0 ? result * -1 : result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed total = area(a, b, c);
	Fixed area1 = area(point, b, c);
	Fixed area2 = area(a, point, c);
	Fixed area3 = area(a, b, point);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;

	return (total == area1 + area2 + area3);
}
