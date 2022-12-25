#include "Conversion.hpp"
#include <cctype>

Conversion::e_type	Conversion::checkType(void) const
{
	size_t	pos;
	size_t	tmp_pos;
	
	if (_str.length() == 1 && isprint(_str[0]) && !isdigit(_str[0]))
		return (Conversion::CHAR_TYPE);

	pos = 0;
	if (_str[pos] == '+' || _str[pos] == '-')
		++pos;
	
	tmp_pos = pos;
	for (; pos < _str.length(); ++pos)
		if (!isdigit(_str[pos]))
			break ;
	if (tmp_pos != pos && _str[pos] == '\0')
		return (Conversion::INT_TYPE);
	
	if (_str[pos] != '.')
		return (Conversion::NO_TYPE);
	
	tmp_pos = pos;
	for (; pos < _str.length(); ++pos)
		if (!isdigit(_str[pos]))
			break ;
	
	if (tmp_pos != pos && _str[pos] == '\0')
		return (Conversion::DOUBLE_TYPE);
	if (_str[pos] == 'f' && _str[pos + 1] == '\0')
		return (Conversion::FLOAT_TYPE);
	return (Conversion::NO_TYPE);
}

Conversion::Conversion(std::string const &str) : _str(str), _type(checkType())
{
}

Conversion::Conversion(Conversion const &sc) : _str(sc._str), _type(sc._type), _char(sc._char), _int(sc._int), _float(sc._float), _double(sc._double)
{
}

Conversion::Conversion(void){}

Conversion::~Conversion(void){}

Conversion&	Conversion::operator=(Conversion const &rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_double = rhs._double;
		this->_float = rhs._float;
		//this->_str = rhs._str;
	}
	return (*this);
}
