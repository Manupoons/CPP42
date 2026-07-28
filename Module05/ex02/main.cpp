/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:40:52 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 11:06:35 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	//Create the 3 forms and some Bureaucrats
	ShrubberyCreationForm shrubbery("garden");
	RobotomyRequestForm robotomy("marvin");
	PresidentialPardonForm pardon("student_42");
	Bureaucrat manu("Manu", 150);
	Bureaucrat lucia("Lucia", 120);
	Bureaucrat mery("Mery", 3);

	std::cout << std::endl << " --------------------- " << std::endl;

	//Try to execute forms without being signed
	{
		try
		{
			std::cout << manu << std::endl;
			std::cout << shrubbery << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;

			//Error because execute without sign
			manu.executeForm(shrubbery);
			manu.executeForm(robotomy);
			manu.executeForm(pardon);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Sign form and try to execute without enough grade
	{
		try
		{
			std::cout << manu << std::endl;
			std::cout << lucia << std::endl;
			std::cout << shrubbery << std::endl;
			shrubbery.beSigned(lucia); //Good because lucia has 120 and shrubbery requires for sign 145 or less
			manu.executeForm(shrubbery); //Error because manu has 150 and shrubbery requires for execute 137 or less
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Sign forms and execute them
	{
		try
		{
			std::cout << mery << std::endl;
			robotomy.beSigned(mery); //Good because mery has 3 and robotomy requires for sign 72 or less
			pardon.beSigned(mery); //Good because mery has 3 and pardon requires for sign 25 or less
			std::cout << shrubbery << std::endl; //lucia sign in the last test
			std::cout << robotomy << std::endl;
			std::cout << pardon << std::endl;

			std::cout << std::endl << " --------------------- " << std::endl;
			mery.executeForm(shrubbery); //Good because manu has 3 and shrubbery requires for execute 137 or less
			std::cout << std::endl << " --------------------- " << std::endl;
			mery.executeForm(robotomy); //Good because manu has 3 and robotomy requires for execute 45 or less
			std::cout << std::endl << " --------------------- " << std::endl;
			mery.executeForm(pardon); //Good because manu has 3 and pardon requires for execute 5 or less
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Trillian");
		ShrubberyCreationForm tardon("Meg");
		std::cout << "\n";

		try
		{
			boss.signForm(robot);
			boss.executeForm(robot);
			std::cout << "\n";

			boss.signForm(pardon);
			boss.executeForm(pardon);
			std::cout << "\n";

			boss.signForm(tardon);
			boss.executeForm(tardon);
			std::cout << "\n";
		} catch (std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	return (0);
}