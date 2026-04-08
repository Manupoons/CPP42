/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:06 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/08 11:52:31 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy" << std::endl;
	this->_brain = new Brain();
	*this = copy;
}

Cat& Cat::operator=(const Cat& assign) {
	std::cout << "Cat assign" << std::endl;
	if (this != &assign)
	{
		this->_type = assign._type;
		*(this->_brain) = *(assign._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(int num, std::string idea) {
	this->_brain->setIdea(num, idea);
}

std::string Cat::getIdea(int num) const {
	return (this->_brain->getIdea(num));
}