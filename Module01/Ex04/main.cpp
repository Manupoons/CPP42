/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 10:23:04 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/20 10:25:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return 1;
	}

	Replace replacer(argv[1], argv[2], argv[3]);
	if (!replacer.process())
		return 1;
	
	std::cout << "Replacement done succesfully." << std::endl;
	return 0;
}