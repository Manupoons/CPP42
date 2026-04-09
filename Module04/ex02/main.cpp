/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:05 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:46:29 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// ❌ This should NOT compile (uncomment to test)
	// AAnimal a;

	AAnimal *zoo[4];
	
	for (int i = 0; i < 2; i++)
	{
		zoo[i] = new Dog();
	}
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
	{
		zoo[i] = new Cat();
	}
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
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