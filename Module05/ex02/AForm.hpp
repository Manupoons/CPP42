/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:08:06 by mamaratr          #+#    #+#             */
/*   Updated: 2026/07/28 11:11:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	
	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		AForm& operator=(const AForm &assign);
		virtual ~AForm();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		
		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		
		class GradeTooHighException: public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual char const *what() const throw();
		};

		class FormNotSignedException: public std::exception {
			public:
				virtual char const *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, AForm const &form);

#endif