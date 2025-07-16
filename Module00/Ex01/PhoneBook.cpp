/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:22:02 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/16 10:06:04 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) {
	this->_index = 0;
	std::cout << "PhoneBook created." << std::endl;
}

PhoneBook::~PhoneBook(void) {
	this->_index = 0;
	std::cout << "PhoneBook destroyed." << std::endl;
}

std::string PhoneBook::promptAndGet(const std::string &prompt) {
	std::string input;
	while (!std::cin.eof() && input.empty()) {
		std::cout << prompt;
		if (std::getline(std::cin, input) && input.empty())
			std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
	return input;
}

void PhoneBook::add(void) {

	std::string str;
	
	if (this->_index > 7)
		std::cout << "Warning: overwriting info about " 
				  << this->_contacts[this->_index % 8].getFirstName()
				  << std::endl;
	int index = this->_index % 8;

	this->_contacts[index].setFirstName(promptAndGet("Enter first name: "));
	this->_contacts[index].setLastName(promptAndGet("Enter " + this->_contacts[index].getFirstName() + "'s last name: "));
	this->_contacts[index].setNickName(promptAndGet("Enter " + this->_contacts[index].getFirstName() + "'s nickname: "));
	this->_contacts[index].setPhoneNumber(promptAndGet("Enter " + this->_contacts[index].getFirstName() + "'s phone number: "));
	this->_contacts[index].setDarkestSecret(promptAndGet("Enter " + this->_contacts[index].getFirstName() + "'s darkest secret: "));

	std::cout << this->_contacts[index].getFirstName() 
			  << " added to PhoneBook [" << index + 1 << "/8]" 
			  << std::endl;
	
	this->_index++;
}

static std::string formatField(const std::string& str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}

void PhoneBook::displayContacts() {
	int i = 0;
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;
	
	while (i < this->_index && i < 8) {
		std::cout << std::setw(10) << i << "|"
				  << formatField(this->_contacts[i].getFirstName()) << "|"
				  << formatField(this->_contacts[i].getLastName()) << "|"
				  << formatField(this->_contacts[i].getNickname()) << std::endl;
		i++;
	}
}

void PhoneBook::search(void) {
	if (this->_index == 0) {
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	
	displayContacts();

	std::string input;
	int index = -1;
	while (!std::cin.eof()) {
		std::cout << "Enter index of contact to display: ";
		if (std::getline(std::cin, input) && !input.empty()) {
			if (input.size() == 1 && input[0] >= '0' && input[0] <= '7') {
				index = input[0] - '0';
				if (index < this->_index)
					break ;
			}
			std::cout << "Invalid index." << std::endl;
		}
	}
	
	if (!std::cin.eof()) {
		Contact contact = this->_contacts[index];
		std::cout << "First Name: " << contact.getFirstName() << std::endl;
		std::cout << "Last Name: " << contact.getLastName() << std::endl;
		std::cout << "Nickname: " << contact.getNickname() << std::endl;
		std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
	}
}
