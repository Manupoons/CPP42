/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 11:19:08 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 12:21:59 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
}

Intern &Intern::operator=(const Intern &assign)
{
	(void)assign;
	return *this;
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string &nameForm, const std::string &target) const
{
	const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*creators[3])(const std::string&) = {createShrubbery, createRobotomy, createPardon};
	
	int i = 0;
	while (i < 3 && nameForm != names[i])
		i++;
	if (i < 3)
	{
		std::cout << "Intern creates " << nameForm << std::endl;
		return (creators[i](target));
	}
	std::cout << "Intern couldn't create form: " << nameForm << std::endl;
	return (NULL);
}

AForm* createShrubbery(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomy(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* createPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}
