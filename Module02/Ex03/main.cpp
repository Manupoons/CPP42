/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:26:01 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/26 11:46:44 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main() {
	Point a(1.0f, 1.0f);
	Point b(5.0f, 1.0f);
	Point c(3.0f, 4.0f);

	Point inside(3.0f, 2.0f);
	Point edge(3.0f, 1.0f);
	Point vertex(1.0f, 1.0f);
	Point outside(0.0f, 0.0f);

	std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
	std::cout << "Point on vertex: " << bsp(a, b, c, vertex) << std::endl;
	std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;

	return 0;
}


// int main() {
// 	Point a(0.0f, 0.0f);
// 	Point b(6.0f, 0.0f);
// 	Point c(3.0f, 6.0f);

// 	Point center(3.0f, 2.0f);
// 	Point nearEdge(3.0f, 0.1f);
// 	Point onEdge(3.0f, 0.0f);
// 	Point onVertex(3.0f, 6.0f);
// 	Point outside(10.0f, 10.0f);
// 	Point below(3.0f, -1.0f);
// 	Point above(3.0f, 7.0f);

// 	std::cout << "Center point (3,2): " << bsp(a, b, c, center) << std::endl;
// 	std::cout << "Near edge (3,0.1): " << bsp(a, b, c, nearEdge) << std::endl;
// 	std::cout << "On edge (3,0): " << bsp(a, b, c, onEdge) << std::endl;
// 	std::cout << "On vertex (3,6): " << bsp(a, b, c, onVertex) << std::endl;
// 	std::cout << "Outside (10,10): " << bsp(a, b, c, outside) << std::endl;
// 	std::cout << "Below (3,-1): " << bsp(a, b, c, below) << std::endl;
// 	std::cout << "Above (3,7): " << bsp(a, b, c, above) << std::endl;

// 	return 0;
// }