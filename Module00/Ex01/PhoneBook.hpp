/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:23:03 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/15 22:51:44 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

	private:
		Contact _contacts[8];
		int _index;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void add(void);
		void search(void);
		void display(Contact contact);
		void displayContacts();
		std::string promptAndGet(const std::string &prompt);
		
		Contact getContact(int index);
};

#endif