/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:54:21 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/04 20:00:52 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

const std::string specials[6] = {
	"nan", "-inf", "+inf", "nanf", "-inff", "+inff"
};

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter & assign)
{
	(void)assign;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool isChar(const std::string &input)
{
	return (input.length() == 1 && !isdigit(input[0]));
}

bool isInt(const std::string &input)
{
	size_t i = 0;

	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]))
			return (false);
	}
	return (true);
}

bool isDouble(const std::string &input)
{
	size_t i = 0;
	int counter = 0;

	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length(); j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return (false);
		if (input[j] == '.')
			counter++;
		if (counter > 1)
			return (false);
	}
	if (counter != 1)
		return (false);
	return (true);
}

bool isFloat(const std::string &input)
{
	size_t i = 0;
	int counter = 0;

	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	if (input[input.length() - 1] != 'f' || (input.length() == 2 && !isdigit(input[0])))
		return (false);
	if (input[0] == '+' || input[0] == '-')
		i = 1;
	for (size_t j = i; j < input.length() - 1; j++)
	{
		if (!isdigit(input[j]) && input[j] != '.')
			return (false);
		if (input[j] == '.')
			counter++;
		if (counter > 1)
			return (false);
	}
	return (true);
}

bool isPseudoLiteral(const std::string &input, type _type)
{
	if (_type == DOUBLE)
	{
		for (int i = 0; i < 3; i++)
		{
			if (input == specials[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << input << "f" << std::endl;
				std::cout << "double: " << input << std::endl;
				return (true);
			}
		}
	}
	else if (_type == FLOAT)
	{
		for (int i = 3; i < 6; i++)
		{
			if (input == specials[i])
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: " << input << std::endl;
				std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
				return (true);
			}
		}
	}
	return (false);
}

type parse(const std::string &input)
{
	if (isChar(input))
		return (CHAR);
	if (isInt(input))
		return (INT);
	if (isDouble(input))
		return (DOUBLE);
	if (isFloat(input))
		return (FLOAT);
	return (ERROR);
}

bool limints(const std::string &input, type _type)
{
	if (_type == INT)
	{
		long	val = std::strtol(input.c_str(), NULL, 10);
		if (val < INT_MIN || val > INT_MAX)
			return (false);
	}
	else if (_type == DOUBLE || _type == FLOAT)
	{
		double val = std::strtod(input.c_str(), NULL);
		if (std::isnan(val) || std::isinf(val))
			return (false);
		if (_type == FLOAT)
		{
			if (val > FLT_MAX || val < -FLT_MIN)
				return (false);
		}
		else
		{
			if (val > DBL_MAX || val < -DBL_MIN)
				return (false);
		}
	}
	return (true);
}

void printChar(const std::string &input)
{
	char c = input[0];

	if (!isprint(c))
		throw (ScalarConverter::InvalidInputException());
	std::cout << "char: " << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printInt(const std::string &input)
 {
	int nb;
	std::stringstream ss(input);
	
	ss >> nb;
	if (nb >= ' ' && nb <= '~' && std::isprint(static_cast<unsigned char>(nb)))
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << nb << ".0f" << std::endl;
	std::cout << "double: " << nb << ".0" << std::endl;
}

void printDouble(const std::string &input, type _type)
{
	double nb;
	std::stringstream ss(input);

	ss >> nb;
	if (!isPseudoLiteral(input, _type))
	{
		if (nb >= ' ' && nb <= '~' && std::isprint(static_cast<unsigned char>(nb)))
			std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
		std::cout << "float: " << nb;
		if (nb == static_cast<int>(nb))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << nb;
		if (nb == static_cast<int>(nb))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void printFloat(const std::string &input, type _type)
{
	float nb;
	std::stringstream ss(input);

	ss >> nb;
	if (!isPseudoLiteral(input, _type))
	{
		if (nb >= ' ' && nb <= '~' && std::isprint(static_cast<unsigned char>(nb)))
			std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(nb) << std::endl;
		std::cout << "float: " << nb;
		if (nb == static_cast<int>(nb))
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(nb);
		if (nb == static_cast<int>(nb))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void converter(const std::string &input, type _type)
{
	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
		{
			if (i < 3)
			{
				printDouble(input, _type);
				return;
			}
			else
			{
				printFloat(input, _type);
				return;
			}
		}
	}
	switch (_type)
	{
		case CHAR:
			printChar(input);
			break;
		case INT:
			printInt(input);
			break;
		case DOUBLE:
			printDouble(input, _type);
			break;
		case FLOAT:
			printFloat(input, _type);
			break;
		default:
			throw ScalarConverter::InvalidInputException();
			break;
	}
}

void ScalarConverter::convert(const std::string &input)
{
	type _type;

	if (input.empty())
		throw (ScalarConverter::InvalidInputException());
	_type = parse(input);
	for (int i = 0; i < 6; i++)
	{
		if (input == specials[i])
		{
			converter(input, _type);
			return;
		}
	}
	if (!limints(input, _type))
	{
		std::cerr << "Error: Overflow detected" << std::endl;
		return;
	}
	converter(input, _type);
}

char const *ScalarConverter::InvalidInputException::what() const throw ()
{
	return ("Invalid input :(");
}