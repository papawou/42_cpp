#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>


int read_file(std::string const &file_path, std::string &str)
{
	std::ifstream ifs(file_path);
	std::ostringstream ostr;

	ostr << ifs.rdbuf();
	if (ostr.fail() || ifs.fail())
	{
		ifs.close();
		return (1);
	}
	str = ostr.str();
	return (0);
}

void format_db(std::string const &str, bool &date_first)
{
	static std::string const date_key = "date";
	static std::string const rate_key = "exchange_rate";
	size_t pos_nl;
	size_t pos_date;
	size_t pos_rate;
	size_t pos_comma;

	pos_comma = str.find_first_of(',');
	if (pos_comma != std::string::npos)
		throw ("comma not found");
	pos_nl = str.find_first_of('\n');
	if (pos_nl == std::string::npos)
		throw("nl not found");
	pos_date = str.find(date_key);
	if (pos_date == std::string::npos || pos_nl < pos_date)
		throw("date error");
	pos_rate = str.find(rate_key);
	if (pos_rate == std::string::npos || pos_nl < pos_rate)
		throw("rate error");
	date_first = pos_date < pos_rate;
}

void parse_line(t_format &format, std::string::const_iterator &it, std::map<std::string, float> &map)
{

}

void	parse_db(std::string const &str, t_format &format, std::map<std::string, float> &map)
{
	size_t i = str.find_first_of('\n') + 1;

	while (1)
	{
		if (str.compare(i, format.pre.length(), format.pre) != 0)
			throw ("invalid pre format");
		i += format.pre.length();
		if (format.date_first)
			//check_date
		else
			//check_other
		if (str.compare(i, format.inter.length(), format.inter) != 0)
			throw ("invalid inter format");
		i += format.inter.length();
		if (format.date_first)
			//check_other
		else
			//check_date
		if (str.compare(i, format.post.length(), format.post) != 0)
			throw ("invalid post format");
		i += format.post.length();
	}
}

int main()
{
	/* int argc char *argv[]
	std::string data_str;
	if (argc != 2)
		return 1;
	if (read_file(argv[1], data_str))
		return 1;
	*/

	std::string db_str;
	bool	date_first;
	std::map<std::string, float> db;

	if (read_file("./bin/data.csv", db_str))
		return 1;
	format_db(db_str, date_first);
	parse_db(db_str, date_firsts, db);
	return (0);
}