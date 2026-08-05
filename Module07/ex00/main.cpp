/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:45:33 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 09:57:02 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main( void )
{
	int	a = 2;
	int	b = 3;

	std::cout << std::endl << "TEST 1" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl << "Swap" << std::endl;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	//comparison of the ASCII number of the first distinct character in both strings
	std::cout << std::endl << "TEST 2" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl << "Swap" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return (0);
}
