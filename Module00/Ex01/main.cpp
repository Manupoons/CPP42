/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:46:42 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/16 10:13:35 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook pb;
	std::string str;

	while (true) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT) > ";
		if (!std::getline(std::cin, str)) {
			std::cout << std::endl;
			break;
		}
		if (str == "ADD")
			pb.add();
		else if (str == "SEARCH")
			pb.search();
		else if (str == "EXIT")
			break ;
		else if (!str.empty())
			std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
	}
	return (0);
}
