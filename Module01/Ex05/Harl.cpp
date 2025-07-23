/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:17:19 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/21 13:47:15 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug() {
	std::cout << "I love having extra bacon for my double-cheese burger." << std::endl;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i]) {
			(this->*functions[i])();
			return;
		}
	}
	
}