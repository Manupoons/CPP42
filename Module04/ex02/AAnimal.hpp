/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:06:31 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/08 12:12:08 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected:
		std::string _type; 

	public:
		AAnimal();
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& assign);
		virtual ~AAnimal();

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif