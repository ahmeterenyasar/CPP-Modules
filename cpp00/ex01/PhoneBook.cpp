/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:45:20 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/30 13:08:44 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Constructor */
PhoneBook::PhoneBook()
{
	_contactCount = 0;
	_oldestIndex = 0;
}

/* Destructor */
PhoneBook::~PhoneBook() {}

/* === Private helper functions === */
std::string PhoneBook::_getInput(const std::string& prompt) {
	std::string input;

	while (true) {
		std::cout << CYAN << prompt << RESET;
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl << RED << "EOF detected. Exiting..." << RESET << std::endl;
			exit(0);
		}
		size_t start = input.find_first_not_of(" \t\n\r");
		if (start == std::string::npos) {
			std::cout << YELLOW << "Field cannot be empty. Please try again." << RESET << std::endl;
			continue;
		}
		size_t end = input.find_last_not_of(" \t\n\r");
		input = input.substr(start, end - start + 1);

		if (!input.empty())
			break;

		std::cout << YELLOW << "Field cannot be empty. Please try again." << RESET << std::endl;
	}
	return input;
}

bool PhoneBook::_isValidIndex(const std::string& input, int& index) {
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
		return false;
	index = input[0] - '0';
	return true;
}

void PhoneBook::_displayHeader() {
	std::cout << BOLD << BLUE
	          << "|" << std::setw(10) << "Index"
	          << "|" << std::setw(10) << "First Name"
	          << "|" << std::setw(10) << "Last Name"
	          << "|" << std::setw(10) << "Nickname"
	          << "|" << RESET << std::endl;
}

void PhoneBook::_displayContactRow(int index, const Contact& contact) {
	std::cout << GREEN
	          << "|" << std::setw(10) << index
	          << "|" << std::setw(10) << contact.truncateString(contact.getFirstName())
	          << "|" << std::setw(10) << contact.truncateString(contact.getLastName())
	          << "|" << std::setw(10) << contact.truncateString(contact.getNickname())
	          << "|" << RESET << std::endl;
}

/* === Public functions === */
void PhoneBook::addContact() {
	Contact newContact;

	std::string firstName = _getInput("Enter first name: ");
	newContact.setFirstName(firstName);

	std::string lastName = _getInput("Enter last name: ");
	newContact.setLastName(lastName);

	std::string nickname = _getInput("Enter nickname: ");
	newContact.setNickname(nickname);

	std::string phoneNumber = _getInput("Enter phone number: ");
	newContact.setPhoneNumber(phoneNumber);

	std::string darkestSecret = _getInput("Enter darkest secret: ");
	newContact.setDarkestSecret(darkestSecret);

	this->_contacts[this->_oldestIndex] = newContact;

	if (this->_contactCount < 8)
		this->_contactCount++;

	this->_oldestIndex = (this->_oldestIndex + 1) % 8;

	std::cout << GREEN << "Contact added successfully!" << RESET << std::endl;
}

void PhoneBook::searchContact() {
	if (this->_contactCount == 0) {
		std::cout << YELLOW << "PhoneBook is empty." << RESET << std::endl;
		return;
	}

	this->displayAllContacts();

	std::string input;
	int index;

	std::cout << CYAN << "Enter the index of the contact to display: " << RESET;
	if (!std::getline(std::cin, input)) {
		std::cout << std::endl << RED << "EOF detected. Exiting..." << RESET << std::endl;
		exit(0);
	}

	if (!this->_isValidIndex(input, index)) {
		std::cout << RED << "Invalid index. Please enter a number between 0 and 7." << RESET << std::endl;
		return;
	}

	if (this->_contacts[index].isEmpty()) {
		std::cout << YELLOW << "No contact found at index " << index << "." << RESET << std::endl;
		return;
	}

	std::cout << std::endl;
	this->_contacts[index].displayContact();
}

void PhoneBook::displayAllContacts() {
	this->_displayHeader();

	for (int i = 0; i < 8; i++) {
		if (!this->_contacts[i].isEmpty()) {
			this->_displayContactRow(i, this->_contacts[i]);
		}
	}
}