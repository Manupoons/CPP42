/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:21:08 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/23 08:16:11 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	std::string level = argv[1];

	int levelIndex = -1;
	std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			levelIndex = i;
			break;
		}
	}

	switch (levelIndex) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
			//fallthrough
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
			//fallthrough
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
			//fallthrough
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}
