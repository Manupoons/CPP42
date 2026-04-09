/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:05 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:01:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl;

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat    = new WrongCat();

	std::cout << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
