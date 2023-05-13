#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

class BitcoinExchange
{
public:
	class BitcoinExchangeOpenFileException : public std::exception
	{
		virtual const char *what() const throw();
	};

	BitcoinExchange(std::string const &path);
	BitcoinExchange(std::map<std::string, float> db);
	BitcoinExchange(BitcoinExchange const &rhs);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	virtual ~BitcoinExchange(void);
private:
	std::map<std::string, float> _db;

	int	read_file(std::string const &file_path, std::string &str) const;

	BitcoinExchange(void);
};

#endif