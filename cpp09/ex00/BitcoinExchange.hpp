/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:01:24 by ayasar            #+#    #+#             */
/*   Updated: 2025/11/13 17:01:25 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, float> _database;

	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& value, float& result) const;
	std::string trim(const std::string& str) const;
	std::string findClosestDate(const std::string& date) const;
	bool isLeapYear(int year) const;

public:
	BitcoinExchange();
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename);
};

#endif
