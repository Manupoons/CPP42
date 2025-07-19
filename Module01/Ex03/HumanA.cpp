/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:48:35 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/19 18:13:54 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (std::string name, Weapon& weapon) : _name(name), _weapon(weapon){
	std::cout << _name << " created with weapon type: " << _weapon.getType()  << std::endl;
};

HumanA::~HumanA () {
	std::cout << _name << " destroyed" << std::endl;
}

void HumanA::attack() const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}