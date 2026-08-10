	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   main.cpp                                           :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2026/08/05 09:59:04 by mamaratr          #+#    #+#             */
	/*   Updated: 2026/08/10 12:06:36 by mamaratr         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "iter.hpp"

	int main()
	{
		{
			std::cout << std::endl << "TEST 1" << std::endl;
			std::cout << std::endl << "int array:" << std::endl;

			int	intArr[] = {42, 38, 1, 14, 23, 87};
			iter(intArr, ARRAY_SIZE(intArr), printElement<int>);

			std::cout << std::endl << "int array (+ 1):" << std::endl;
			iter(intArr, ARRAY_SIZE(intArr), sumOne);

			std::cout << std::endl << "int array after mutation:" << std::endl;
			iter(intArr, ARRAY_SIZE(intArr), printElement<int>);
		}

		{
			std::cout << std::endl << "TEST 2" << std::endl;
			std::cout << std::endl << "char array:" << std::endl;

			char	charArr[] = {'a', 'b', 'c', 'd'};
			iter(charArr, ARRAY_SIZE(charArr), printElement<char>);
		}

		{
			std::cout << std::endl << "TEST 3" << std::endl;
			std::string	strArr[] = {"Hola", "que", "tal", "soy", "Manu", ":))"};
			
			std::cout << std::endl << "string array:" << std::endl;
			iter(strArr, ARRAY_SIZE(strArr), printElement<std::string>);
		}
		return (0);
	}