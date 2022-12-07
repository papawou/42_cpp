#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "bad usage" << std::endl;
		return (1);
	}
	{
		Harl h;
		h.complain(argv[1]);
	}
	std::cout << std::endl;
	{
		Harl h("debug", "info", "warning", "error");
		h.complain(argv[1]);
	}
	return (0);
}
