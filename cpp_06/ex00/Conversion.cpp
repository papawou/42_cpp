#include "Conversion.hpp"
#include <cctype>
#include <iostream>

Conversion::e_type	Conversion::checkType(void) const
{
	size_t	pos;
	size_t	tmp_pos;

	if (_str.compare("-inff"))
		return MINFF_TYPE;
	else if (_str.compare("+inff"))
		return INFF_TYPE;
	else if (_str.compare("-inf"))
		return MINF_TYPE;
	else if (_str.compare("+inf"))
		return INF_TYPE;
	else if (_str.compare("nan"))
		return NAN_TYPE;
	else if (_str.compare("nanf"))
		return NANF_TYPE;

	if (_str.length() == 1 && !isdigit(_str[0])) 
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

void	Conversion::castType(void)
{

}

void	Conversion::castFloat(void)
{
	std::cout << "float: ";
	switch (_type)
	{
		case Conversion::FLOAT_TYPE:
			//
			break;
		case Conversion::CHAR_TYPE:
			_float = static_cast<float>(_char);
			break;
		case Conversion::DOUBLE_TYPE:
			_float = static_cast<float>(_double);
			break;
		case	Conversion::INT_TYPE:
			_float = static_cast<float>(_int);
			break;
		default:
			std::cout << "Impossible" << std::endl;
	}

	if (!isprint(_float))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << _float << std::endl;
}

void	Conversion::castDouble(void)
{
	bool impossible = false;

	std::cout << "double: ";
	switch (_type)
	{
		case Conversion::DOUBLE_TYPE:
			//
			break;
		case Conversion::CHAR_TYPE:
			_double = static_cast<double>(_char);
			break;
		case Conversion::FLOAT_TYPE:
			_double = static_cast<double>(_float);
			break;
		case	Conversion::INT_TYPE:
			_double = static_cast<double>(_int);
			break;
		default:
			impossible = true;
	}

	if (impossible)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << _double << std::endl;
}

void	Conversion::castChar(void)
{
	bool impossible = false;

	std::cout << "char: ";
	switch (_type)
	{
		case Conversion::CHAR_TYPE:
			_char = _str[0];
			break;
		case Conversion::FLOAT_TYPE:
			_char = static_cast<char>(_float);
			break;
		case Conversion::DOUBLE_TYPE:
			_char = static_cast<char>(_double);
			break;
		case	Conversion::INT_TYPE:
			_char = static_cast<char>(_int);
			break;
		default:
			impossible = true;
	}

	if (impossible)
		std::cout << "Impossible" << std::endl;
	else if (!isprint(_char))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << _char << std::endl;
}

void	Conversion::castInt(void)
{
	
}

Conversion::Conversion(std::string const &str) : _str(str), _type(checkType()){}

Conversion::Conversion(Conversion const &sc) : _str(sc._str), _type(sc._type), _char(sc._char), _int(sc._int), _float(sc._float), _double(sc._double){}

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
