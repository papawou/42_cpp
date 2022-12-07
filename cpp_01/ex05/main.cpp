#include "Harl.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "Harl default" << std::endl;
		Harl hp;
		for (int i = 0; i < 4; ++i)
			hp.complain(Harl::lvls[i]);
	}
	std::cout << std::endl;
	{
		std::cout << "Harl custom" << std::endl;
		Harl hp("debug", "info", "warning", "error");
		for (int i = 0; i < 4; ++i)
			hp.complain(Harl::lvls[i]);
	}
}