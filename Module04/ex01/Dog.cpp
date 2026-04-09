/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:17 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:49:08 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& copy) : Animal(copy) {
	std::cout << "Dog copy" << std::endl;
	this->_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog& assign) {
	std::cout << "Dog assign operator" << std::endl;
	if (this != &assign)
	{
		this->_type = assign._type;
		delete this->_brain;
		this->_brain = new Brain(*assign._brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete this->_brain;
}

void Dog::makeSound() const{
	std::cout << "Woof woof!" << std::endl;
}

void Dog::setIdea(int num, std::string idea) {
	this->_brain->setIdea(num, idea);
}

std::string Dog::getIdea(int num) const {
	return (this->_brain->getIdea(num));
}