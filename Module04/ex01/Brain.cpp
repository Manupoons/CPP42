/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:29:19 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/09 11:30:56 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain& copy) {
	std::cout << "Brain copy" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=(const Brain& assign) {
	std::cout << "Brain assign" << std::endl;
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = assign._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor" << std::endl;
}

void Brain::setIdea(int num, std::string idea) {
	if (num >= 0 && num <=99)
		this->_ideas[num] = idea;
	else
		std::cout << "Invalid idea number" << std::endl;
}

std::string Brain::getIdea(int num) const {
	if (num >= 0 && num <=99)
		return this->_ideas[num];
	else
		return ("Invalid idea number");
}