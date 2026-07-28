/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:08:06 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 08:46:35 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		Form& operator=(const Form &assign);
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		//void setIsSigned();
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException: public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual char const *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif