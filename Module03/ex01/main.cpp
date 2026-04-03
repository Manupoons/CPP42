/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:56:00 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 18:56:02 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int	main()
{
	ScavTrap scav("SC4V-TP");

	std::cout << GREEN << "\n[Action] ";
	scav.attack("target1");
	std::cout << "[Action] ";
	scav.guardGate();
	std::cout << "[Action] ";
	scav.takeDamage(30);
	std::cout << "[Action] ";
	scav.beRepaired(20);
	std::cout << RESET << std::endl;
	return 0;
}