/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:53:36 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/03 19:04:16 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_mana= 100;
	this->_atk = 30;
	std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->_name << " wants a high five!" << std::endl;
}
