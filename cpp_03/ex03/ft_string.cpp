#include <string>
#include <iostream>
#include <sstream>

void	ft_putstr(std::string const &str)
{
	std::cout << str << std::endl;
}

std::string ft_itoa(int n)
{
	std::ostringstream tmp;
	tmp << n;
	return tmp.str();
}