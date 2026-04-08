/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:07:13 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/08 12:14:54 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
	private:
		Brain* _brain;

	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& assign);
		virtual ~Cat();

		virtual void makeSound(void) const;
		void setIdea(int num, std::string idea);
		std::string getIdea(int num) const;
};

#endif