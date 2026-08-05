/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:59:04 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 10:11:33 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template< typename T >
void print(T& x)
{
	std::cout << x << std::endl;
	return;
}

void add_5(int& a)
{
	a += 5;
}

void add_5(float& a)
{
	a += 5;
}

int main(void)
{
	{
		std::cout << "--- Case 1: print array function TEMPLATE ---" << std::endl;
		std::cout << "test 1: char array:" << std::endl;
		char arr1[4] = {'c', 'h', 'a', 'r'};
		size_t size1 = 4;
		iter(arr1, size1, print);
		std::cout << std::endl;

		std::cout << "test 2: int array:" << std::endl;
		int arr2[3] = {1, 3, 5};
		int size2 = 3;
		iter(arr2, size2, print<const long>);
		std::cout << std::endl;

		std::cout << "test 3: string array:" << std::endl;
		std::string arr3[4] = {"This", "is", "42", "Madrid"};
		float size3 = 4.7f;
		iter(arr3, size3, print);
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "--- Case 2: add 5 function ---" << std::endl;
		std::cout << "test 1: int array:" << std::endl;
		int arr1[3] = {1, 3, 5};
		double size1 = 3.523423;
		iter(arr1, size1, add_5);
		for (int i = 0; i < 3; i++) {
			std::cout << arr1[i] << std::endl;
		}
		std::cout << std::endl;

		std::cout << "test 2: float array:" << std::endl;
		float arr2[3] = {4.5f, 3.8f, 10.2f};
		long size2 = 3;
		iter(arr2, size2, add_5);
		for (int i = 0; i < 3; i++) {
			std::cout << arr2[i] << std::endl;
		}
		std::cout << std::endl;
	}
}