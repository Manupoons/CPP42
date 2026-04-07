/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:31 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/07 10:45:26 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected:
		std::string _type; 

	public:
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& assign);
		virtual ~Animal();

		virtual void makeSound(void) const;
		std::string getType(void) const;
};

#endif