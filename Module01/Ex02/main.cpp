/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:05:16 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/19 17:23:59 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void) {
	std::string msg = "HI THIS IS BRAIN";
	
	std::string *stringPTR = &msg;
	std::string &stringREF = msg;

	std::cout << "Mem address string var: " << &msg << std::endl;
	std::cout << "Mem address stringPTR: " << stringPTR << std::endl;
	std::cout << "Mem address stringREF: " << &stringREF << std::endl;

	std::cout << "Value string var: " << msg << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;

	return (0);
}