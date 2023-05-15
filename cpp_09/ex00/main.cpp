#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>


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