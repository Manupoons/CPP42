/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:55:19 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 18:55:20 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

int	main() {
	ClapTrap clapTrap("Clappy");

	std::cout << RED << "[Action] ";
	clapTrap.attack("target");
	std::cout << RESET;

	std::cout << YELLOW << "[Action] ";
	clapTrap.takeDamage(5);
	std::cout << RESET;

	std::cout << GREEN << "[Action] ";
	clapTrap.beRepaired(3);
	std::cout << RESET;

	return 0;
}
