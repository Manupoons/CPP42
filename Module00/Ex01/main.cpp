/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:46:42 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/15 23:00:06 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook pb1;
	std::string str;

	while (str != "EXIT")
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb1.add();
		else if (str == "SEARCH")
			pb1.search();
		if (std::cin.eof()) //if ctrlD -> \n
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}