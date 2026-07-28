/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:08:03 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 08:56:38 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute): _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
		throw (Form::GradeTooLowException());
	else if (this->_gradeToSign < 1 || this->_gradeToExecute < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(Form const &copy): _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form::~Form(void)
{
}

Form &Form::operator=(const Form &assign)
{
	if (this != &assign)
		this->_isSigned = assign._isSigned;
	return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}


int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (Form::GradeTooLowException());
}

char const *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	return (out << "Form name: " << form.getName() << ", is signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute() << std::endl);
}
