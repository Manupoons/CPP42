/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 10:35:21 by mamaratr          #+#    #+#             */
/*   Updated: 2026/09/02 20:08:40 by mamaratr         ###   ########.fr       */
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
		char *end;
		double value = strtod(valueStr.c_str(), &end);
		if (*end != '\0')
			continue;

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
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	if (!isDigitString(yearStr) || !isDigitString(monthStr) || !isDigitString(dayStr))
		return (false);

	int y = atoi(yearStr.c_str());
	int m = atoi(monthStr.c_str());
	int d = atoi(dayStr.c_str());

	if (m < 1 || m > 12 || d < 1 || d > 31)
		return (false);

	static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int maxDay = daysInMonth[m - 1];
	if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
		maxDay = 29;

	return (d <= maxDay);
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
		bool exactMatch = (it != _database.end() && it->first == date);
		if (!exactMatch)
		{
			if (it == _database.begin())
				throw DateTooOldException();
			--it;
		}
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

const char* BitcoinExchange::DateTooOldException::what() const throw()
{
	return "Error: date is too old";
}