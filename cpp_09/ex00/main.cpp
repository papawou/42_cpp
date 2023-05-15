#include <string>
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
		btc.process(argv[1]);
	}
	catch (std::exception const &e)
	{
		std::cerr << "DB: " << e.what() << std::endl;
	}

	return (0);
}