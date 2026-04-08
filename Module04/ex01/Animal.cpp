/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:33 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/07 10:45:14 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal& copy) {
	std::cout << "Animal copy" << std::endl;
	*this = copy;
}

Animal& Animal::operator=(const Animal& assign) {
	std::cout << "Animal assign operator" << std::endl;
	if (this != &assign) {
		this->_type = assign._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

void Animal::makeSound() const {
	std::cout << "Good morning!" << std::endl;
}

std::string Animal::getType() const{
	return this->_type;
}