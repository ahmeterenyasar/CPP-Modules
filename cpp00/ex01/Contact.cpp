/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:45:24 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/30 13:10:56 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* Constructor */
Contact::Contact() {
}

/* Destructor */
Contact::~Contact() {
}

/* Setters */
void Contact::setFirstName(const std::string& firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
	this->_lastName = lastName;
}

void Contact::setNickname(const std::string& nickname) {
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

/* Getters */
std::string Contact::getFirstName() const {
	return this->_firstName;
}

std::string Contact::getLastName() const {
	return this->_lastName;
}

std::string Contact::getNickname() const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return this->_darkestSecret;
}

/* Utility functions */
bool Contact::isEmpty() const {
	return (this->_firstName.empty() || this->_lastName.empty() ||
			this->_nickname.empty() || this->_phoneNumber.empty() ||
			this->_darkestSecret.empty());
}

void Contact::displayContact() const {
	std::cout << std::endl;
	std::cout << BOLD << BLUE << "Contact Information" << RESET << std::endl;
	std::cout << MAGENTA << "First Name     : " << RESET << this->_firstName << std::endl;
	std::cout << MAGENTA << "Last Name      : " << RESET << this->_lastName << std::endl;
	std::cout << MAGENTA << "Nickname       : " << RESET << this->_nickname << std::endl;
	std::cout << MAGENTA << "Phone Number   : " << RESET << this->_phoneNumber << std::endl;
	std::cout << MAGENTA << "Darkest Secret : " << RESET << this->_darkestSecret << std::endl;
	std::cout << std::endl;
}

std::string Contact::truncateString(const std::string& str) const {
	if (str.length() > 10) {
		return str.substr(0, 9) + ".";
	}
	return str;
}
