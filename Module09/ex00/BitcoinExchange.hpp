/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:35:19 by mamaratr          #+#    #+#             */
/*   Updated: 2026/09/02 19:35:51 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <climits>
# include <map>
# include <cmath>
# include <sstream>
# include <stdexcept>

# define DATA_CSV "data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, double> _database;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string &dbFile);
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange &assign);
		~BitcoinExchange();

		void loadDatabase(const std::string &filename);
		void processInputFile(const std::string &filename) const;

		class FailOpenFileException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class WrongHeaderFileException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DateTooOldException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif