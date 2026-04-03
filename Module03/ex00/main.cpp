/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:51:01 by mamaratr          #+#    #+#             */
/*   Updated: 2025/08/07 18:33:05 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

int	main() {
	std::cout << CYAN << "Creating ClapTrap:" << RESET << std::endl;
	ClapTrap clapTrap("Clappy");

	std::cout << std::endl;

	std::cout << RED << "[Action] ";
	clapTrap.attack("target");
	std::cout << RESET;

	std::cout << YELLOW << "[Action] ";
	clapTrap.takeDamage(5);
	std::cout << RESET;

	std::cout << GREEN << "[Action] ";
	clapTrap.beRepaired(3);
	std::cout << RESET;

	std::cout << std::endl;

	return 0;
}
