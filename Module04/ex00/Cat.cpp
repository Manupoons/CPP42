/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:06 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 10:58:28 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat& copy) : Animal(copy) {
	std::cout << "Cat copy" << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat& assign) {
	std::cout << "Cat assign" << std::endl;
	if (this != &assign)
		this->_type = assign._type;
	return *this;
}

Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meow Meow!" << std::endl;
}