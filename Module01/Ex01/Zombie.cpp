/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:43:55 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/19 17:00:46 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	this->name = "";
	std::cout << "Zombie " << this->name
			  << " created" << std::endl;
}

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "Zombie " << this->name
			  << " created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->name
			  << " destroyed" << std::endl;
}

std::string Zombie::getName(void) const {
	return (this->name);
}

void Zombie::setName(std::string str) {
	this->name = str;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..."
			  << std::endl;
}