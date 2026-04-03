/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:50:55 by mamaratr          #+#    #+#             */
/*   Updated: 2025/08/02 18:18:42 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap constructor called for " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
				  << ", causing " << this->attackDamage << " points of damage!"
				  << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints <= 0)
		std::cout << "ClapTrap " << this->name
				  << " has no energy points left to attack!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name
				  << " is out of hit points and cannot attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > amount)
		this->hitPoints -= amount;
	else
		this->hitPoints = 0;
	std::cout << "ClapTrap " << this->name << " takes " << amount
			  << " points of damage! Remaining hit points: "
			  << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0 && this->hitPoints > 0)
	{
		this->hitPoints += amount;
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " repairs itself for "
				  << amount << " hit points! Current hit points: "
				  << this->hitPoints << std::endl;
	}
	else if (this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name
				  << " has no energy points left to repair!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name <<
				  " is out of hit points and cannot be repaired!" << std::endl;
}
