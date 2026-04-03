/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:55:43 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 18:55:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hp = 0;
	this->_mana = 0;
	this->_atk = 0;
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hp > 0 && this->_mana > 0)
	{
			std::cout << "ClapTrap " << this->_name << " attacks " << target
					<< ", causing " << this->_atk << " points of damage!" << std::endl;
			this->_mana--;
	}
	else if (this->_hp <= 0)
		std::cout << "ClapTrap is out of hit points and can't attack!" << std::endl;
	else
		std::cout << "ClapTrap has no mana left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << "ClapTrap " << this->_name << " takes "
			<< amount << " points of damage! Remaining hitpoints: "
			<< this->_hp << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp > 0)
	{
		if (this->_mana > 0)
		{
			std::cout << "ClapTrap " << _name << " healed " << amount
					<< " hp!" << std::endl;
			this->_hp += amount;
			this->_mana--;
		}
		else
			std::cout << "ClapTrap " << _name
					<< " couldn't be healed because it has no energy left!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " couldn't be healed!" << std::endl;
}
