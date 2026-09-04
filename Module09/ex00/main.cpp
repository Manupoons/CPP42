/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:30:53 by mamaratr          #+#    #+#             */
/*   Updated: 2026/09/02 19:18:42 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int check_args(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Wrong use - ./btc 'file.txt'" << std::endl;
		return (1);
	}
	
	std::ifstream infile;
	infile.open(argv[1]);
	if (!infile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char const **argv)
{
	if (check_args(argc, argv) == 1)
		return (1);
	
	try
	{
		BitcoinExchange btc(DATA_CSV);
		btc.processInputFile(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
