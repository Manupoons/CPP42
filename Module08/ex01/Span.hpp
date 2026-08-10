/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:36:52 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 11:41:23 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iostream>
#include <algorithm>

class Span
{
	private:
		std::vector<int> stock;
		unsigned int limit;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &assign);
		~Span();

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		void addNumbers(std::vector<int>::iterator listBegin, std::vector<int>::iterator listEnd);

		void print_vector();
};

#endif