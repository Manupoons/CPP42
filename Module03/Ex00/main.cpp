/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:51:01 by mamaratr          #+#    #+#             */
/*   Updated: 2025/08/02 18:20:01 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap("Clappy");

	std::cout << " " << std::endl;
	
	clapTrap.attack("target");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(3);
	
	std::cout << " " << std::endl;
}