/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:17 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/07 10:46:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy" << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog& assign) {
	std::cout << "Dog assign operator" << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Woof woof!" << std::endl;
}