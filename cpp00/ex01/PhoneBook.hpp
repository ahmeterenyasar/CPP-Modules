/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:45:17 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/21 16:35:10 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include "Colors.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class PhoneBook {
private:
	Contact		_contacts[8];
	int			_contactCount;
	int			_oldestIndex;   

	std::string	_getInput(const std::string& prompt);
	bool		_isValidIndex(const std::string& input, int& index);
	void		_displayHeader();
	void		_displayContactRow(int index, const Contact& contact);

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact();
	void	displayAllContacts();
};

#endif