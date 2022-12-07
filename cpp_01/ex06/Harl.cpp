#include "Harl.hpp"
#include <iostream>
#include <string>

Harl::Harl(void)
{
	_debug = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !";
	_info = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !";
	_warning = "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.";
	_error = "This is unacceptable ! I want to speak to the manager now.";
}

Harl::Harl(std::string const &debug, std::string const &info, std::string const &warning, std::string const &error) : _debug(debug), _info(info), _warning(warning), _error(error){}

Harl::e_lvls Harl::getLvl(std::string const &lvl)
{
	for (int i = 0; i < 4; ++i)
	{
		if (lvl == Harl::lvls[i])
			return ((Harl::e_lvls) i);
	}
	return (Harl::UNDEFINED);
}

void Harl::complain(std::string level) const
{
	switch (getLvl(level))
	{
		case Harl::UNDEFINED:
			std::cout << "undefined complain..." << std::endl;
			break ;
		case Harl::DEBUG:
			debug();
		case Harl::INFO:
			info();
		case Harl::WARNING:
			warning();
		case Harl::ERROR:
			error();
	}
}

void Harl::debug(void) const
{
	std::cout << _debug << std::endl;
}

void Harl::info(void) const
{
	std::cout << _info << std::endl;
}

void Harl::warning(void) const
{
	std::cout << _warning << std::endl;
}

void Harl::error(void) const
{
	std::cout << _error << std::endl;
}

std::string const Harl::lvls[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};