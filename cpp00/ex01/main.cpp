/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:23:45 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/21 16:41:38 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PhoneBook.hpp"

void printWelcome() {
	std::cout << BOLD << GREEN << "\nWelcome to My Awesome PhoneBook!" << RESET << std::endl;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	printWelcome();

	while (true) {
		std::cout << std::endl;
		std::cout << CYAN << "Enter a command (ADD / SEARCH / EXIT): " << RESET;

		if (!std::getline(std::cin, command)) {
			std::cout << std::endl << RED << "EOF detected. Exiting..." << RESET << std::endl;
			break;
		}

		if (command == "ADD") {
			phoneBook.addContact();
		}
		else if (command == "SEARCH") {
			phoneBook.searchContact();
		}
		else if (command == "EXIT") {
			std::cout << GREEN << "Goodbye!" << RESET << std::endl;
			break;
		}
		else if (!command.empty()) {
			std::cout << YELLOW << "Invalid command." << RESET << std::endl;
			std::cout << MAGENTA << "Available commands: ADD, SEARCH, EXIT" << RESET << std::endl;
		}
	}

	return 0;
}
