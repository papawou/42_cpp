#include "Conversion.hpp"
#include <cctype>

Conversion::e_type	Conversion::checkType(void)
{
	if (_str.length() == 0)
		return Conversion::NO_TYPE;
	if (checkChar())
		return Conversion::CHAR_TYPE;
	if (checkInt())
		return Conversion::INT_TYPE;
	if (checkFloat())
		return Conversion::FLOAT_TYPE;
	if (checkDouble())
		return Conversion::DOUBLE_TYPE;
}

bool	Conversion::checkChar(void)
{
	if (_str.length() != 1)
		return false;
	return (isprint(_str[0]));
}

bool	Conversion::checkInt(void)
{
	size_t pos;

	pos = 0;
	if (_str[pos] == '+' || _str[pos] == '-')
		++pos;
	for(; pos < _str.length(); ++pos)
	{
		if (!isdigit(_str[pos]))
			return (false);
	}
	return (true);
}

bool	Conversion::checkFloat(void) const
{
	size_t pos;

	pos = 0;

	if (_str[pos] == '+' || _str[pos] == '-')
		++pos;
	for(; pos < _str.length(); ++pos)
		if (!isdigit(_str[pos]))
			break ;
	
	if (pos == 0) //no digits
		return (false);
	if (_str.find_first_of("."))
		return (false);	
	size_t	e_pos;
	if (pt_pos == std::string::npos)
	{
		e_pos = _str.find_first_of("e");
		if (e_pos)
			
	}
}

Conversion::Conversion(std::string const &str) : _str(str)
{
}

Conversion::Conversion(Conversion const &sc) : _str(sc._str){}

Conversion::Conversion(void){}

Conversion::~Conversion(void){}

Conversion&	Conversion::operator=(Conversion const &rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}
