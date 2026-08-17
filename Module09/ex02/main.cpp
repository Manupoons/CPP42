/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 08:46:15 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/17 10:55:48 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void printSequence(const std::string &label, const std::vector<long> &seq)
{
	std::cout << label;
	for (size_t i = 0; i < seq.size(); i++)
		std::cout << seq[i] << " ";
	std::cout << std::endl;
}


int main(int argc, char **argv)
{
	std::vector<long> input;

	try
	{
		input = PmergeMe::parseArgs(argc, argv);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	printSequence("Before: ", input);
	
	std::vector<long> vectorInput(input.begin(), input.end());
	std::deque<long> dequeInput(input.begin(), input.end());

	std::clock_t startVector = std::clock();
	std::vector<long> sortedVector = PmergeMe::sortVector(vectorInput);
	std::clock_t endVector = std::clock();

	std::clock_t startDeque = std::clock();
	std::deque<long> sortedDeque = PmergeMe::sortDeque(dequeInput);
	std::clock_t endDeque = std::clock();

	printSequence("After: ", sortedVector);

	double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000.0;
	double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << std::fixed;
	std::cout.precision(5);
	std::cout << "Time to process range of " << input.size()
		<< " elements with std::vector: " << timeVector << " us" << std::endl;
	std::cout << "Time to process range of " << input.size()
		<< " elements with std::deque: " << timeDeque << " us" << std::endl;

	return (0);
}