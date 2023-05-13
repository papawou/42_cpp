



bool check_valid_date(std::string const &date)
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

std::string parse_date(std::string const &date)
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

float parse_value(std::string const &value)
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

void parse_line(size_t &i, std::string const &delim, std::string const &str, std::string &first, std::string &second)
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

void db_add_pair(std::string const &date, std::string const &value, std::map<std::string, float> &map)
{
	std::string date_map = parse_date(date);
	float f = parse_value(value);

	std::pair<std::map<std::string, float>::const_iterator, bool> ret;
	ret = map.insert(std::pair<std::string, float>(date_map, f));
	if (!ret.second)
		throw("map duplicate key");
}

void db_parse(bool date_first, std::string const &str, std::map<std::string, float> &map)
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
			db_add_pair(first, second, map);
		else
			db_add_pair(second, first, map);
	}
	if (map.empty())
		throw("map has no entries");
}

void db_check_conf(std::string const &str, std::string const &first, std::string const &second)
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

void db_format(std::string const &str, std::map<std::string, float> &map)
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
	db_parse(date_first, str, map);
}

bool getlineHelper(std::istringstream &is, std::string &line)
{
	getline(is, line);
	if (is.fail())
		throw("getline fail occured");
	return is.eof();
}

void input_format(std::string const &str, std::map<std::string, float> const &db)
{
	std::istringstream is(str);
	std::string line;
	std::string first;
	std::string second;
	std::string date;
	float value;
	size_t i;

	if (str.empty())
		throw ("file is empty");
	getlineHelper(is, line);
	if (line.compare("date | value") == 0)
	{
		if (is.eof())
			throw("no entries provided");
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

			std::map<std::string, float>::const_iterator it = db.lower_bound(first);
			if (it->first != date)
			{
				if (it != db.cbegin())
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
		getlineHelper(is, line);
	} while (line.length());
}

int main(int argc, char *argv[])
{
	std::string db_str;
	std::map<std::string, float> db;
	std::string input_str;

	if (argc != 2)
	{
		std::cerr << "Missing file argument" << std::endl;
		return 1;
	}

	if (read_file("./input.csv", db_str))
	{
		std::cerr << "csv error while reading file" << std::endl;
	}

	try
	{
		db_format(db_str, db);
	}
	catch (const char *e)
	{
		std::cerr << "DB " << e << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "DB " << e.what() << std::endl;
	}

	if (read_file(argv[1], input_str))
	{
		std::cerr << "INPUT failed to read" << std::endl;
		return (1);
	}
	try
	{
		input_format(input_str, db);
	}
	catch (const char *e)
	{
		std::cerr << "INPUT " << e << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cerr << "INPUT " << e.what() << std::endl;
	}

	return (0);
}