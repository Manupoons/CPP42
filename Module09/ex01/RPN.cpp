/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:38:12 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/11 13:50:45 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const std::string &input): _input(input)
{
}

RPN::RPN(const RPN &copy): _input(copy._input)
{
}

RPN &RPN::operator=(const RPN &assign)
{
	if (this != &assign)
		this->_input = assign._input;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::RPNCalculator()
{
	std::stack<int> tokens;
	std::stringstream ss(this->_input);
	std::string item;
	
	while (ss >> item)
	{
		if (item.length() != 1)
			throw ErrorException();

		char c = item[0];
		if (std::isdigit(c))
			tokens.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (tokens.size() < 2)
				throw ErrorException();
			
			int b = tokens.top();
			tokens.pop();
			int a = tokens.top();
			tokens.pop();
			
			if (c == '+')
				tokens.push(a + b);
			else if (c == '-')
				tokens.push(a - b);
			else if (c == '*')
				tokens.push(a * b);
			else
			{
				if (b == 0)
					throw ErrorException("division by zero");
				tokens.push(a / b);
			}
		}
		else
			throw ErrorException();
	}
	if (tokens.size() != 1)
		throw ErrorException();
	std::cout << tokens.top() << std::endl;
}

std::string RPN::getInput() const
{
	return (this->_input);
}

void RPN::setInput(const std::string &input)
{
	this->_input = input;
}

const char* RPN::ErrorException::what() const throw()
{
	return ((_message).c_str());
}