/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:05 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:32:12 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	Animal *zoo[6];
	
	for (int i = 0; i < 3; i++)
	{
		zoo[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 3; i < 6; i++)
	{
		zoo[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		delete zoo[i];
	}
	std::cout << std::endl;

	Cat* original = new Cat();
	Cat* copy = new Cat();
	std::cout << std::endl;
	original->setIdea(0, "I am the original");
	copy->setIdea(0, "I am the copy");
	std::cout << std::endl;
	std::cout << "Original: " << original->getIdea(0) << std::endl;
	std::cout << "Copy: " << copy->getIdea(0) << std::endl;
	std::cout << std::endl;
	*copy = *original;
	std::cout << "Original: " << original->getIdea(0) << std::endl;
	std::cout << "Copy: " << copy->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	delete original;
	delete copy;

	return 0;
}
