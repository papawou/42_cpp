#include "BitcoinExchange.hpp"

void BitcoinExchange::read_file(std::string const &file_path, std::string &str) const
{
	std::ifstream ifs(file_path);
	std::ostringstream ostr;

	if (!ifs)
		throw BitcoinExchange::BitcoinExchangeFileException();
	if (ifs.peek() == std::ifstream::traits_type::eof())
		return;
	ostr << ifs.rdbuf();
	if (ifs.fail() || ostr.fail())
		throw BitcoinExchange::BitcoinExchangeFileException();
	str = ostr.str();
}

BitcoinExchange::BitcoinExchange(std::string const &path) : _db()
{
	load_path(path);
}

BitcoinExchange::BitcoinExchange(std::map<std::string, float> db) : _db(db)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) : _db(rhs._db)
{
}

BitcoinExchange::BitcoinExchange(void) : _db()
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

bool BitcoinExchange::check_valid_date(std::string const &date) const
{
	std::istringstream is(date);
	std::string year;
	std::string month;
	std::string day;

	std::getline(is, year, '-');
	if (is.fail())
		throw("valid_date YEAR error");
	std::getline(is, month, '-');
	if (is.fail())
		throw("valid_date MONTH error");
	std::getline(is, day);
	if (is.fail())
		throw("valid_date DAY error");
	int int_year = stoi(year);
	int int_month = stoi(month);
	int int_day = stoi(day);

	if (int_month < 1 || int_month > 12)
		return false;
	if (int_day < 1 || int_day > 31)
		return false;
	if (int_month == 4 || int_month == 6 || int_month == 9 || int_month == 11)
		return (int_day <= 30);
	if (int_month == 2)
	{
		if (((int_year % 4 == 0) && (int_year % 100 != 0)) || (int_year % 400 == 0))
			return int_day <= 29;
		else
			return int_day <= 28;
	}
	return true;
}

std::string BitcoinExchange::parse_date(std::string const &date) const
{
	size_t i = 0;

	if (date.empty())
		throw("DATE not found");
	i = 0;
	for (; isdigit(date[i]); ++i)
	{
	}
	if (i != 4 || date[i] != '-')
		throw("DATE expected year");
	++i;
	for (; isdigit(date[i]); ++i)
	{
	}
	if (i != 7 || date[i] != '-')
		throw("DATE expected month");
	++i;
	for (; isdigit(date[i]); ++i)
	{
	}
	if (i != 10 || date[i] != '\0')
		throw("DATE expected day");
	if (!check_valid_date(date))
		throw("DATE is invalid");
	return date;
}

float BitcoinExchange::parse_value(std::string const &value) const
{
	float f;
	std::istringstream is(value);

	if (value.empty())
		throw("NUMBER not found");
	is >> f;
	if (is.fail())
		throw("NUMBER conversion failed");
	return f;
}

void BitcoinExchange::parse_line(size_t &i, std::string const &delim, std::string const &str, std::string &first, std::string &second) const
{
	size_t pos_delim;

	first.clear();
	second.clear();
	pos_delim = str.find(delim, i);
	if (pos_delim == std::string::npos)
		throw("line delimiter not found");
	for (; i != pos_delim; ++i)
		first.push_back(str[i]);
	i += delim.length();
	for (; str[i] && str[i] != '\n'; ++i)
		second.push_back(str[i]);
}

void BitcoinExchange::db_add_pair(std::string const &date, std::string const &value)
{
	std::string date_map = parse_date(date);
	float f = parse_value(value);

	std::pair<std::map<std::string, float>::const_iterator, bool> ret;
	ret = _db.insert(std::pair<std::string, float>(date_map, f));
	if (!ret.second)
		throw("map duplicate key");
}

void BitcoinExchange::db_parse(bool date_first, std::string const &str)
{
	std::string first;
	std::string second;
	size_t i = 0;

	for (; str[i] && str[i] != '\n'; ++i)
	{
	}
	if (str[i])
		++i;
	for (; str[i]; ++i)
	{
		parse_line(i, ",", str, first, second);
		if (date_first)
			db_add_pair(first, second);
		else
			db_add_pair(second, first);
	}
}

void BitcoinExchange::db_check_conf(std::string const &str, std::string const &first, std::string const &second)
{
	if (str.compare(0, first.length(), first) != 0)
		throw("unknown first key");
	if (str[first.length()] != ',')
		throw("unfound comma");
	if (str.compare(first.length() + 1, second.length(), second) != 0)
		throw("unknown second key");
	if (str[first.length() + second.length() + 1] != '\n')
		throw("expected at end of keys \\n");
}

void BitcoinExchange::db_format(std::string const &str)
{
	static std::string const date_key = "date";
	static std::string const rate_key = "exchange_rate";
	bool date_first;

	if (str.empty())
		throw("file is empty");
	date_first = str[0] == date_key[0];
	if (date_first)
		db_check_conf(str, date_key, rate_key);
	else
		db_check_conf(str, rate_key, date_key);
	db_parse(date_first, str);
}

bool BitcoinExchange::getlineHelper(std::istringstream &is, std::string &line) const
{
	getline(is, line);
	return is.eof();
}

void BitcoinExchange::input_format(std::string const &str) const
{
	std::istringstream is(str);
	std::string line;
	std::string first;
	std::string second;
	std::string date;
	float value;
	size_t i;

	if (str.empty())
		return;
	getlineHelper(is, line);
	if (line.compare("date | value") == 0)
	{
		if (is.eof())
			return;
		getlineHelper(is, line);
	}

	do
	{
		i = 0;
		try
		{
			parse_line(i, " | ", line, first, second);
			date = parse_date(first);
			value = parse_value(second);

			if (value < 0)
				throw("Number < 0");
			if (1000 < value)
				throw("Number > 1000");

			std::map<std::string, float>::const_iterator it = _db.lower_bound(first);
			if (it->first != date)
			{
				if (it != _db.cbegin())
					--it;
				else
					throw("can't find valide DATE");
			}
			std::cout << date << ": " << (value * it->second) << std::endl;
		}
		catch (char const *err)
		{
			std::cerr << line << " !> " << err << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << line << " !> " << e.what() << std::endl;
		}
		line.clear();
		if (is.eof())
			break;
	} while (!getlineHelper(is, line));
}

void BitcoinExchange::process(std::string const &path) const
{
	std::string value;

	read_file(path, value);
	input_format(value);
}

void BitcoinExchange::set_map(std::map<std::string, float> const db)
{
	for (std::map<std::string, float>::iterator it; it != db.end(); ++it)
	{
		try
		{
			if (check_valid_date(it->first))
				throw "";
			if (it->second < 0)
				throw "";
		}
		catch (const char *e)
		{
			throw BitcoinExchangeDatabaseException();
		}
	}
	_db = db;
}

void BitcoinExchange::load_path(std::string const &path)
{
	std::string str;

	read_file(path, str);
	try
	{
		db_format(str);
	}
	catch (const char *e)
	{
		throw BitcoinExchange::BitcoinExchangeDatabaseException();
	}
}

const char *BitcoinExchange::BitcoinExchangeFileException::what() const throw()
{
	return ("can't open file");
}

const char *BitcoinExchange::BitcoinExchangeDatabaseException::what() const throw()
{
	return ("invalid database");
}