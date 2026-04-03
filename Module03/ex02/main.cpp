/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:54:50 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 19:05:48 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int	main()
{
	FragTrap frag("fraggy");

	std::cout << GREEN << "\n[Action] ";
	frag.highFivesGuys();
	std::cout << "[Action] ";
	frag.attack("froggo");
	std::cout << RESET << std::endl;
	return 0;
}