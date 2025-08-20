/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:45:22 by ayasar            #+#    #+#             */
/*   Updated: 2025/07/21 16:41:05 by ayasar           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "Colors.hpp"
#include <string>
#include <iostream>

class Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();

	/* Setters */
	void	setFirstName(const std::string& firstName);
	void	setLastName(const std::string& lastName);
	void	setNickname(const std::string& nickname);
	void	setPhoneNumber(const std::string& phoneNumber);
	void	setDarkestSecret(const std::string& darkestSecret);

	/* Getters */
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	/* Utility functions */
	bool		isEmpty() const;
	void		displayContact() const;
	std::string	truncateString(const std::string& str) const;
};

#endif