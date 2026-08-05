/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 13:53:58 by mamaratr          #+#    #+#             */
/*   Updated: 2026/08/05 08:45:32 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	serialized;
	Data		*deserialized;

	data.str = "Hola!";
	deserialized = NULL;

	std::cout << std::endl << "\t-- POINTER COMPARISON --" << std::endl;
	if (&data == deserialized)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are different" << std::endl;

	std::cout << std::endl << "\t-- ORIGINAL DATA --" << std::endl;
	std::cout << "Pointer: " << &data << std::endl;
	std::cout << "String : " << data.str << std::endl;

	std::cout << std::endl << "\t-- SERIALIZATION --" << std::endl;
	serialized = Serializer::serialize(&data);
	std::cout << "Serialized value: " << serialized << std::endl;

	std::cout << std::endl << "\t-- DESERIALIZATION --" << std::endl;
	deserialized = Serializer::deserialize(serialized);
	std::cout << "Pointer: " << deserialized << std::endl;
	std::cout << "String : " << deserialized->str << std::endl;

	std::cout << std::endl << "\t-- POINTER COMPARISON --" << std::endl;
	if (&data == deserialized)
		std::cout << "Pointers are equal" << std::endl;
	else
		std::cout << "Pointers are different" << std::endl;

	return (0);
}
