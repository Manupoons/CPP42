/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:54:55 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 19:00:50 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_mana= 50;
	this->_atk = 20;
	std::cout << "ScavTrap constructor called for " << this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_mana > 0 && this->_hp > 0) {
		std::cout << "ScavTrap attacks " << target << ", causing "
				  << this->_atk << " points of damage!" << std::endl;
		this->_mana--;
	}
	else if (this->_hp <= 0)
		std::cout << "ScavTrap is out of hit points and can't attack!" << std::endl;
	else
		std::cout << "ScavTrap has no mana left!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is in Gate keep mode." << std::endl;
}
