#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl
{
public:
	enum	e_lvls {DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3, UNDEFINED = -1};
	static	Harl::e_lvls getLvl(std::string const &lvl);
	static	std::string const lvls[4];
	
	Harl(void);
	Harl(std::string const &debug, std::string const &info, std::string const &warning, std::string const &error);
	void	complain(std::string level) const;
private:
	std::string _debug;
	std::string _info;
	std::string _warning;
	std::string	_error;

	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
};

#endif