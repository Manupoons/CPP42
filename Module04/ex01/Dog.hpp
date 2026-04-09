/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:19 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:10:11 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain* _brain;
	
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& assign);
		~Dog();
		
		void makeSound(void) const;
		void setIdea(int num, std::string idea);
		std::string getIdea(int num) const;
};

#endif