/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:51:01 by mamaratr          #+#    #+#             */
/*   Updated: 2025/08/07 18:36:21 by mamaratr         ###   ########.fr       */
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
	std::cout << CYAN << "Creating ScavTrap:" << RESET << std::endl;
	ScavTrap scav("SC4V-TP");

	std::cout << GREEN << "\n[Action] ";
	scav.attack("target1");
	std::cout << GREEN << "[Action] ";
	scav.guardGate();
	std::cout << GREEN << "[Action] ";
	scav.takeDamage(30);
	std::cout << GREEN << "[Action] ";
	scav.beRepaired(20);

	std::cout << std::endl << MAGENTA << "ScavTrap going out of scope:" << RESET << std::endl;
	return 0;
}