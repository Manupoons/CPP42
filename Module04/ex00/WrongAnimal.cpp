/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:07:23 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:00:14 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
	std::cout << "WrongAnimal copy" << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& assign) {
	std::cout << "WrongAnimal assign operator" << std::endl;
	if (this != &assign) {
		this->_type = assign._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong animal!" << std::endl;
}

std::string WrongAnimal::getType() const{
	return this->_type;
}