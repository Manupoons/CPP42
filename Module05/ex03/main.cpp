/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:40:52 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 12:26:12 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		bob;
	AForm		*form;
	Bureaucrat	manu("Manu", 50);
	Bureaucrat	president("President", 1);

	std::cout << std::endl << " --------------------- " << std::endl;

	//Test how all forms are created properly execpt for the last one
	{
		try
		{
			form = bob.makeForm("robotomy request", "Alice");
			delete form;
			form = bob.makeForm("shrubbery creation", "Charlie");
			delete form;
			form = bob.makeForm("presidential pardon", "David");
			delete form;
			form = bob.makeForm("random request", "Elisa"); //Error because the form doesn't exist
			delete form;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	//Test some Actions with available form
	{
		form = bob.makeForm("shrubbery creation", "Fred");
		form->beSigned(manu); //Good because manu has 50 and this shrubbery form requires for sign 145 or less
		manu.executeForm(*form); //Good because manu has 50 and this shrubbery form requires for execute 137 or less
		delete form;
	}

	std::cout << std::endl << " --------------------- " << std::endl;

	{
		form = bob.makeForm("presidential pardon", "Georgia");
		manu.signForm(*form); //Error because manu has 50 and this pardon form requires for sign 25 or less
		manu.executeForm(*form); //Error because manu has 50 and this pardon form requires for execute 5 or less
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
	}

	std::cout << std::endl << " --------------------- " << std::endl;
	return (0);
}
