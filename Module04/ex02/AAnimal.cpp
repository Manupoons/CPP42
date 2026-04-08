/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:33 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/08 12:12:17 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy) {
	std::cout << "AAnimal copy" << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& assign) {
	std::cout << "AAnimal assign operator" << std::endl;
	if (this != &assign) {
		this->_type = assign._type;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor" << std::endl;
}

std::string AAnimal::getType() const{
	return this->_type;
}