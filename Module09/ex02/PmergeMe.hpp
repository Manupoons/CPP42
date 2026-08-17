/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:46:10 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/17 09:02:00 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <climits>

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &assign);
		~PmergeMe();

		static std::vector<size_t> sortIndxVector(std::vector<size_t> indices, const std::vector<long> &vals);
		static std::deque<size_t> sortIndxDeque(std::deque<size_t> indices, const std::deque<long> &vals);

	public:
		static std::vector<long> parseArgs(int argc, char **argv);
		
		static std::vector<long> sortVector(std::vector<long> input);
		static std::deque<long> sortDeque(std::deque<long> input);

		class ErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif