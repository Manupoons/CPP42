/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 10:29:24 by mamaratr          #+#    #+#             */
/*   Updated: 2026/04/08 10:45:35 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& assign);
		~Brain();

		void setIdea(int num, std::string idea);
		std::string getIdea(int num) const;
};

#endif