/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:01:26 by ayasar            #+#    #+#             */
/*   Updated: 2025/11/13 17:01:27 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_database = other._database;
	}
	return *this;
}

std::string BitcoinExchange::trim(const std::string& str) const {
	size_t start = 0;
	size_t end = str.length();
	while (start < end && std::isspace(str[start]))
		start++;
	
	while (end > start && std::isspace(str[end - 1]))
		end--;

	return str.substr(start, end - start);
}

bool BitcoinExchange::isLeapYear(int year) const {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	
	return false;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10)
		return false;
	
	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++) {
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return false;
	}

	int year, month, day;
	std::stringstream ss(date);
	char dash;
	ss >> year >> dash >> month >> dash >> day;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 2) {
		if (isLeapYear(year)) {
			if (day > 29)
				return false;
		} else {
			if (day > 28)
				return false;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return false;
	}
	
	return true;
}

bool BitcoinExchange::isValidValue(const std::string& value, float& result) const {
	std::stringstream ss(value);
	ss >> result;

	if (ss.fail() || !ss.eof())
		return false;

	return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open database file.");
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = line.substr(0, commaPos);
		std::string rateStr = line.substr(commaPos + 1);

		float rate;
		std::stringstream ss(rateStr);
		ss >> rate;

		if (!ss.fail() && isValidDate(date)) {
			_database[date] = rate;
		}
	}

	file.close();
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	if (it != _database.end() && it->first == date) {
		return it->first;
	}

	if (it == _database.begin()) {
		return "";
	}

	--it;
	return it->first;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string dateStr = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(dateStr)) {
			std::cout << "Error: bad input => " << dateStr << std::endl;
			continue;
		}

		float value;
		if (!isValidValue(valueStr, value)) {
			std::cout << "Error: bad value input => " << valueStr << std::endl;
			continue;
		}

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::string closestDate = findClosestDate(dateStr);
		if (closestDate.empty()) {
			std::cout << "Error: no data available for date => " << dateStr << std::endl;
			continue;
		}

		float rate = _database[closestDate];
		float result = value * rate;

		std::cout << dateStr << " => " << value << " = " << result << std::endl;
	}

	file.close();
}
