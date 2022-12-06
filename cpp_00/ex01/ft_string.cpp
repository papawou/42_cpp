#include <string>
#include <iostream>

bool	is_digits(std::string const &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

void	ft_nonempty_getline(std::string &str, const char *prefix = nullptr)
{
	do
	{
		if(std::cin == NULL)
			std::exit(1);
		if (prefix != nullptr)
			std::cout << prefix;
		getline(std::cin, str);
		while (std::iswspace(str.back()))
			str.pop_back();
	} while (str.empty());
}

void ft_getint(std::string &str, const char *prefix)
{
	do
	{
		ft_nonempty_getline(str, prefix);
		if (str.find_first_not_of("0123456789") == std::string::npos)
			return ;
	} while (1);
}

std::string ft_truncate(std::string str)
{
	if (std::strlen(str.c_str()) > 10)
		return (str = str.substr(0, 9) + '.');
	return (str);
}
