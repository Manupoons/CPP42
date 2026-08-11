/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:51:06 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/11 08:34:07 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"
 
template <typename T>
void	printArray(const Array<T> &arr, const std::string &name)
{
	std::cout << name << " (size " << arr.size() << "): [ ";
	for (int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << "]" << std::endl;
}

int	main(void)
{
	std::cout << "\t-- DEFAULT CONSTRUCTOR --" << std::endl;
	Array<int>	empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	std::cout << std::endl << "\t-- SIZED CONSTRUCTOR (n = 0) --" << std::endl;
	Array<int>	zero(0);
	std::cout << "zero size: " << zero.size() << std::endl;

	std::cout << std::endl << "\t-- SIZED CONSTRUCTOR (n = 5) --" << std::endl;
	Array<int>	nums(5);
	for (int i = 0; i < nums.size(); i++)
		nums[i] = i * 10;
	printArray(nums, "nums");

	std::cout << std::endl << "\t-- COPY CONSTRUCTOR --" << std::endl;
	Array<int>	copy(nums);
	copy[0] = 999;
	printArray(nums, "nums (original, should be unchanged)");
	printArray(copy, "copy (modified)");

	std::cout << std::endl << "\t-- ASSIGNMENT OPERATOR --" << std::endl;
	Array<int>	assigned;
	assigned = nums;
	assigned[1] = -1;
	printArray(nums, "nums (original, should be unchanged)");
	printArray(assigned, "assigned (modified)");

	std::cout << std::endl << "\t-- SELF ASSIGNMENT --" << std::endl;
	assigned = assigned;
	printArray(assigned, "assigned (after self-assign)");

	std::cout << std::endl << "\t-- STRING ARRAY --" << std::endl;
	Array<std::string>	words(3);
	words[0] = "Hola";
	words[1] = "Adios";
	words[2] = "42";
	printArray(words, "words");

	std::cout << std::endl << "\t-- CONST ARRAY (const operator[]) --" << std::endl;
	const Array<int>	constNums(nums);
	printArray(constNums, "constNums");

	std::cout << std::endl << "\t-- OUT OF BOUNDS (negative index) --" << std::endl;
	try
	{
		std::cout << nums[-1] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\t-- OUT OF BOUNDS (index == size) --" << std::endl;
	try
	{
		std::cout << nums[nums.size()] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "\t-- OUT OF BOUNDS on const array --" << std::endl;
	try
	{
		std::cout << constNums[100] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	return (0);
}