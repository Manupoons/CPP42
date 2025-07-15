/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaratr <mamaratr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:28:20 by mamaratr          #+#    #+#             */
/*   Updated: 2025/07/15 19:31:27 by mamaratr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void) const {
	return (this->firstName);
}

std::string Contact::getLastName(void) const {
	return (this->lastName);
}

std::string Contact::getNickname(void) const {
	return (this->nickname);
}

std::string Contact::getPhoneNumber(void) const {
	return (this->phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
	return (this->darkestSecret);
}

void Contact::setFirstName(std::string str) {
	this->firstName = str;
}

void Contact::setLastName(std::string str) {
	this->lastName = str;
}

void Contact::setNickName(std::string str) {
	this->nickname = str;
}

void Contact::setPhoneNumber(std::string str) {
	this->phoneNumber = str;
}

void Contact::setDarkestSecret(std::string str) {
	this->darkestSecret = str;
}

