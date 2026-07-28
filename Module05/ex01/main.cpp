/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:40:52 by mamaratr          #+#    #+#             */
/*   Updated: 2026/05/20 12:56:06 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling constructor with grade too high
	{
		try
		{
			Bureaucrat	manu("manu", 0); //Error because the maximum is 1
			std::cout << manu << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling constructor with grade too low
	{
		try
		{
			Bureaucrat	manu("manu", 151); //Error because the minimum is 150
			std::cout << manu << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling gradeUp
	{
		try
		{
			Bureaucrat	manu("manu", 3);
			std::cout << manu << std::endl;
			manu.gradeUp(); //grade = 2
			std::cout << manu << std::endl;
			manu.gradeUp(); //grade = 1
			std::cout << manu << std::endl;
			manu.gradeUp(); //grade = 0 -> Error
			std::cout << manu << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Throw exception when calling gradeDown
	{
		try
		{
			Bureaucrat	manu("manu", 149);
			std::cout << manu << std::endl;
			manu.gradeDown(); //grade = 150
			std::cout << manu << std::endl;
			manu.gradeDown(); //grade = 151 -> Error
			std::cout << manu << std::endl;
			manu.gradeDown();
			std::cout << manu << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;
	return (0);
}