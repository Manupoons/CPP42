/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 12:38:09 by mamaratr          #+#    #+#             */
/*   Updated: 2026/09/02 20:18:11 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::string _input;
		
	public:
		RPN();
		RPN(const std::string &input);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &assign);
		~RPN();

		void RPNCalculator();

		class ErrorException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif