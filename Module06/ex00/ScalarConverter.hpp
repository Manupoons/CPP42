/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:54:23 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/04 14:16:43 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>
# include <cfloat>
# include <cmath>
# include <sstream>
# include <iomanip>
# include <cstdlib>
# include <exception>

extern const std::string specials[6];

enum type
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
	ERROR
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &assign);
		~ScalarConverter();
	
	public:
		static void convert(const std::string &str);
		
		class InvalidInputException: public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif