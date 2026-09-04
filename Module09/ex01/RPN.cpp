/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:38:12 by mamaratr          #+#    #+#             */
/*   Updated: 2026/09/02 20:24:46 by mamaratr         ###   ########.fr       */
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

static int applyOperator(char op, int left, int right)
{
	if (op == '+')
		return (left + right);
	if (op == '-')
		return (left - right);
	if (op == '*')
		return (left * right);
	if (right == 0)
		throw RPN::ErrorException();
	return (left / right);
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
			
			int right = tokens.top();
			tokens.pop();
			int left = tokens.top();
			tokens.pop();
			tokens.push(applyOperator(c, left, right));
		}
		else
			throw ErrorException();
	}
	if (tokens.size() != 1)
		throw ErrorException();
	std::cout << tokens.top() << std::endl;
}

const char* RPN::ErrorException::what() const throw()
{
	return "Error";
}