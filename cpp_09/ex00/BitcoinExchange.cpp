#include "BitcoinExchange.hpp"

void BitcoinExchange::read_file(std::string const &file_path, std::string &str) const
{
	std::ifstream ifs(file_path);
	std::ostringstream ostr;

	if (!ifs)
		throw BitcoinExchange::BitcoinExchangeOpenFileException();
	if (ifs.peek() == std::ifstream::traits_type::eof())
	{
		str = "";
		return ;
	}
	ostr << ifs.rdbuf();
	if (ifs.fail() || ostr.fail())
		throw("error occured while parsing");
	str = ostr.str();
}

BitcoinExchange::BitcoinExchange(std::string const &path)
{
	std::string str;
	read_file(path, str);
	db_format(db_str, db);
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> db) : _db(db)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) : _db(rhs._db)
{
}

BitcoinExchange::BitcoinExchange(void)
{
}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		this->_db = rhs._db;
	}
	return (*this);
}
BitcoinExchange::~BitcoinExchange(void)
{
}

const char *BitcoinExchange::BitcoinExchangeOpenFileException::what() const throw()
{
	return ("error while opening file");
}
