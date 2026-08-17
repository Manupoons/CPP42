/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 11:21:36 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/17 11:37:19 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <string>
#include <vector>
#include <deque>
#include <list>

int main(void) {
	{
		std::cout << "--- Test vector ---" << std::endl;
		std::vector<int> numbers;
		numbers.reserve(5);
		numbers.push_back(1);
		numbers.push_back(5);
		numbers.push_back(9);
		numbers.push_back(7);
		numbers.push_back(5);
		std::cout << "Vector: ";
		for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		
		int num = 5;
		try {
			std::vector<int>::iterator it = easyfind(numbers, num);
			std::cout <<"Search: " << num << ". Position: " << it - numbers.begin() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		
		num = 19;
		try {
			std::vector<int>::iterator it = easyfind(numbers, num);
			std::cout << "Search: " << num << ". Position: " << it - numbers.begin() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Search: " << num << ". " << e.what() << std::endl;
		}
		
		std::cout << std::endl;
	}
	{
		std::cout << "--- Test deque ---" << std::endl;
		std::deque<int> numbers;
		numbers.push_back(1);
		numbers.push_back(3);
		numbers.push_back(9);
		numbers.push_back(7);
		numbers.push_back(5);
		std::cout << "Deque: ";
		for (std::deque<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		
		int num = 5;
		try {
			std::deque<int>::iterator it = easyfind(numbers, num);
			std::cout <<"Search: " << num << ". Position: " << it - numbers.begin() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		
		num = 10;
		try {
			std::deque<int>::iterator it = easyfind(numbers, num);
			std::cout << "Search: " << num << ". Position: " << it - numbers.begin() << std::endl;
		} catch (std::exception& e) {
			std::cout << "Search: " << num << ". " << e.what() << std::endl;
		}
		
		std::cout << std::endl;
	}
	{
		std::cout << "--- Test list ---" << std::endl;
		std::list<int> numbers;
		numbers.push_back(12);
		numbers.push_back(47);
		numbers.push_front(9);
		numbers.push_back(70);
		numbers.push_front(85);
		std::cout << "List: ";
		for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		
		int num = 70;
		try {
			easyfind(numbers, num);
			std::cout <<"Search: " << num << ". Found!" << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		
		num = 10;
		try {
			easyfind(numbers, num);
			std::cout << "Search: " << num << ". Found!" << std::endl;
		} catch (std::exception& e) {
			std::cout << "Search: " << num << ". " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}