/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:08:03 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 10:37:41 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (AForm::GradeTooLowException());
	else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (AForm::GradeTooHighException());
}

AForm::AForm(AForm const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm::~AForm(void)
{
}

AForm &AForm::operator=(const AForm &assign)
{
	if (this != &assign)
		this->_isSigned = assign._isSigned;
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}


int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (AForm::GradeTooLowException());
}

char const *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

char const *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
}

std::ostream &operator<<(std::ostream &str, AForm const &AForm)
{
	str << "Name: " << AForm.getName() << std::endl;
	str << "isSigned: ";
	if (AForm.getIsSigned())
		str << "true" << std::endl;
	else
		str << "false" << std::endl;
	str << "Grade to sign: " << AForm.getGradeToSign() << std::endl;
	str << "Grade to execute: " << AForm.getGradeToExecute() << std::endl;
	return (str);
}
