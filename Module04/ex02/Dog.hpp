/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:19 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/08 12:14:49 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
	private:
		Brain* _brain;
	
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& assign);
		virtual ~Dog();
		
		virtual void makeSound(void) const;
		void setIdea(int num, std::string idea);
		std::string getIdea(int num) const;
};

#endif