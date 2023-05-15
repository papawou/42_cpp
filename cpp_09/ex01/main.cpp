#include <iostream>
#include <string>

#include "RPN.hpp"

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		std::cout << "expect an argument" << std::endl;
		return (1);
	}

	try
	{
		std::string str(argv[1]);
		int n = RPN::process(str);
		std::cout << "Result: " << n << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}