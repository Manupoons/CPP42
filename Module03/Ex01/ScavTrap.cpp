/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:34:15 by mamaratr          #+#    #+#             */
/*   Updated: 2025/08/07 18:28:42 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << this->name << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->energyPoints > 0 && this->hitPoints > 0) {
		std::cout << "ScavTrap attacks " << target << ", causing "
				  << this->attackDamage << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0)
		std::cout << "ScavTrap has not attack energy left!" << std::endl;
	else
		std::cout << "ScavTrap out of hit points and can't attack!" << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->name << " is in Gate keep mode." << std::endl;
}
