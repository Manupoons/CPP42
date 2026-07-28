/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:40:52 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 10:18:39 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl << " --------------------- " << std::endl;

	//Create a form with grade too high
	{
		try
		{
			Form form0("Form0", 0, 5); //Error because the maximum is 1
			std::cout << form0 << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Create form and sign it without exceptions
	{
		try
		{
			Bureaucrat manu("Manu", 15);
			Form form1("Form1", 20, 45);
			std::cout << manu << std::endl;
			std::cout << form1 << std::endl; //Form without sign
			manu.signForm(form1); //Good because 15 <= 20
			std::cout << form1 <<  std::endl; //Form after sign
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Create form and try to sign it but the grade is not enough
	{
		try
		{
			Bureaucrat manu("Manu", 35);
			Form form2("form2", 20, 45);
			std::cout << manu << std::endl;
			std::cout  << form2 << std::endl; //Form without sign
			manu.signForm(form2); //Error because 35 NO <= 20
			std::cout  << form2 << std::endl; //Form after sign
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;
	return (0);
}