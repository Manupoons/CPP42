/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:35:21 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/31 13:42:47 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &dbFile)
{
	loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _database(copy._database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	if (this != &assign)
		_database = assign._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw FailOpenFileException();
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date, valueStr;

		if (!std::getline(iss, date, ',') || !std::getline(iss, valueStr))
			continue;
		double value = atof(valueStr.c_str());
		_database[date] = value;
	}
}

static bool isDigitString(const std::string &str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

static bool validateDate(const std::string &date)
{
	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	if (!isDigitString(date.substr(0, 4)) ||
		!isDigitString(date.substr(5, 2)) ||
		!isDigitString(date.substr(8, 2)))
		return (false);
	
	int y = atoi(date.substr(0, 4).c_str());
	int m = atoi(date.substr(5, 2).c_str());
	int d = atoi(date.substr(8, 2).c_str());

	if (m < 1 || m > 12 || d < 1 || d > 31)
		return (false);

	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		daysInMonth[1] = 29;

	if (d > daysInMonth[m - 1])
		return (false);
	return (true);
}

static bool parseLine(const std::string &line, std::string &date, double &value)
{
	std::string delimiter = " | ";

	size_t pos = line.find(delimiter);
	if (pos == std::string::npos)
		return (false);
	date = line.substr(0, pos);
	std::string valueStr = line.substr(pos + delimiter.length());

	char *end;
	value = strtod(valueStr.c_str(), &end);

	if (*end != '\0')
		return (false);
	return (validateDate(date));
}

void BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file)
		throw FailOpenFileException();
	
	std::string line;
	std::getline(file, line);
	if (line != "date | value")
		throw WrongHeaderFileException();
	
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;
		std::string date;
		double value;
		double result;

		if (!parseLine(line, date, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (value < 0)
		{
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large number" << std::endl;
			continue;
		}
		std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
		if (it != _database.begin() && (it == _database.end() || it->first > date))
			--it;

		result = value * it->second;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}

const char* BitcoinExchange::FailOpenFileException::what() const throw()
{
	return "Error: could not open file";
}

const char* BitcoinExchange::WrongHeaderFileException::what() const throw()
{
	return "Error: wrong input header";
}