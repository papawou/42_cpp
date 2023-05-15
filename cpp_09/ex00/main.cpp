#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Missing file argument" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange btc("./data.csv");
	}
	catch (std::exception const &e)
	{
		std::cerr << "DB " << e.what() << std::endl;
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