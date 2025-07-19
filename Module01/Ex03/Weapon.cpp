/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:27:09 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/19 18:05:33 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon () {
	std::cout << "Weapon created" << std::endl;
}

Weapon::Weapon (std::string name) {
	this->type = name;
	std::cout << "Weapon with type: " << type << " created" << std::endl;
}

Weapon::~Weapon () {
	std::cout << "Weapon with type: " << type << " destroyed" << std::endl;
}

const std::string& Weapon::getType() const{
	return this->type;
}

void Weapon::setType (std::string type) {
	this->type = type;
}