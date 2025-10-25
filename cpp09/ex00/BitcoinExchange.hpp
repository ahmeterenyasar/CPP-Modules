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

public:
	BitcoinExchange();
	~BitcoinExchange();

	void loadDatabase(const std::string& filename);
	void processInputFile(const std::string& filename);
};

#endif
