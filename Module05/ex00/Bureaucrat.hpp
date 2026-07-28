/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:40:55 by mamaratr          #+#    #+#             */
/*   Updated: 2026/06/03 11:05:28 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& assign);
		~Bureaucrat();

		std::string getName(void) const;
		int getGrade(void) const;
		void gradeUp(void);
		void gradeDown(void);

		class GradeTooHighException: public std::exception {
			public:
				virtual char const *what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual char const *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif