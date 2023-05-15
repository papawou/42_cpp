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
	class BitcoinExchangeFileException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class BitcoinExchangeDatabaseException : public std::exception
	{
		virtual const char *what() const throw();
	};

	void process(std::string const &path) const;

	BitcoinExchange(std::string const &path);
	BitcoinExchange(std::map<std::string, float> db);
	BitcoinExchange(BitcoinExchange const &rhs);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	virtual ~BitcoinExchange(void);
private:
	std::map<std::string, float> _db;

	bool check_valid_date(std::string const &date) const;
	std::string parse_date(std::string const &date) const;
	float parse_value(std::string const &value) const;
	void parse_line(size_t &i, std::string const &delim, std::string const &str, std::string &first, std::string &second) const;
	void db_add_pair(std::string const &date, std::string const &value);
	void db_parse(bool date_first, std::string const &str);
	void db_check_conf(std::string const &str, std::string const &first, std::string const &second);
	void db_format(std::string const &str);
	void input_format(std::string const &str) const;

	bool getlineHelper(std::istringstream &is, std::string &line) const;
	void	read_file(std::string const &file_path, std::string &str) const;
	BitcoinExchange(void);
};

#endif