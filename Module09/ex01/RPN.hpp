/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:38:09 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/11 13:25:34 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <climits>

class RPN
{
	private:
		std::string _input;
		RPN();
	
	public:
		RPN(const std::string &input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &assign);
		~RPN();

		void RPNCalculator();

		std::string getInput() const;
		void setInput(const std::string &input);
		
		class ErrorException: public std::exception
		{
			private:
				std::string _message;
			public:
				ErrorException(): _message("Error") {}
				ErrorException(const std::string &message): _message("Error: " + message) {}
				virtual ~ErrorException() throw() {}
				virtual const char* what() const throw();
		};
};

#endif