#include "Conversion.hpp"
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cerrno>
#include <limits>
#include <iomanip>
#include <cfloat>

Conversion::e_type	Conversion::checkType(void) const
{
	size_t	pos;
	size_t	tmp_pos;

	if (!_str.compare("-inf") || !_str.compare("-inff"))
		return MINF_TYPE;
	else if (!_str.compare("+inf") || !_str.compare("+inff"))
		return INF_TYPE;
	else if (!_str.compare("nan") || !_str.compare("nanf"))
		return NAN_TYPE;
	if (_str.length() == 1 && !isdigit(_str[0])) 
		return (Conversion::CHAR_TYPE);
	
	pos = 0;
	if (_str[pos] == '+' || _str[pos] == '-')
		++pos;
	
	tmp_pos = pos;
	for (; pos < _str.length(); pos++)
		if (!isdigit(_str[pos]))
			break ;
	
	if (tmp_pos != pos && _str[pos] == '\0')
		return (Conversion::INT_TYPE);
	if (tmp_pos == pos || _str[pos] != '.')
		return (Conversion::NO_TYPE);
	++pos;
	tmp_pos = pos;
	for (; pos < _str.length(); pos++)
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
	std::cout << _type << std::endl;
	void (Conversion::* const funcs[4])(void) = {&Conversion::castChar, &Conversion::castInt, &Conversion::castFloat, &Conversion::castDouble};
	
	if (_type < 4)
		(this->*funcs[_type])();
	
	for (int i = 0; i < 4; i++)
	{
		if (_type == i)
			continue ;
		(this->*funcs[i])();
	}
}

void	Conversion::castFloat(void)
{
	bool impossible = false;

	std::cout << "float: ";
	switch (_type)
	{
		case Conversion::FLOAT_TYPE:
		{
			char *endPtr = NULL;
			double inputResult = strtod(_str.c_str(), &endPtr);
			if ((errno == ERANGE && (inputResult == -HUGE_VAL || inputResult == HUGE_VAL)) && inputResult < FLT_MIN && inputResult > FLT_MAX)
				throw std::exception();
			else
				_float = static_cast<float>(inputResult);
			break;
		}
		case Conversion::CHAR_TYPE:
			_float = static_cast<float>(_char);
			break;
		case Conversion::DOUBLE_TYPE:
			if (_double < FLT_MIN && _double > FLT_MAX)
				impossible = true;
			else
				_float = static_cast<float>(_double);
			break;
		case Conversion::INT_TYPE:
			_float = static_cast<float>(_int);
			break;
		default:
			impossible = true;
	}
	if (_type == INF_TYPE)
		std::cout << "+inff" << std::endl;
	else if (_type == MINF_TYPE)
		std::cout << "-inff" << std::endl;
	else if (_type == NAN_TYPE)
		std::cout << "nanf" << std::endl;
	else if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << _float << 'f' << std::endl;
}

void	Conversion::castDouble(void)
{
	bool impossible = false;

	std::cout << "double: ";
	switch (_type)
	{
		case Conversion::DOUBLE_TYPE:
		{
			char *endPtr = NULL;
			_double = strtod(_str.c_str(), &endPtr);
			if (errno == ERANGE && (_double == -HUGE_VAL || _double == HUGE_VAL))
				throw std::exception();
			break;
		}
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
	if (_type == INF_TYPE)
		std::cout << "+inf" << std::endl;
	else if (_type == MINF_TYPE)
		std::cout << "-inf" << std::endl;
	else if (_type == NAN_TYPE)
		std::cout << "nan" << std::endl;
	else if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << std::setprecision(1) << std::fixed << _double << std::endl;
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
			if (_float > 255 || _float < 0)
				impossible = true;
			else
				_char = static_cast<char>(_float);
			break;
		case Conversion::DOUBLE_TYPE:
			if (_double > 255 || _double < 0)
				impossible = true;
			else
				_char = static_cast<char>(_double);
			break;
		case	Conversion::INT_TYPE:
			if (_int > 255 || _int < 0)
				impossible = true;
			else
				_char = static_cast<char>(_int);
			break;
		default:
			impossible = true;
	}

	if (impossible)
		std::cout << "impossible" << std::endl;
	else if (!isprint(_char))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << '\'' <<  _char << '\''<< std::endl;
}

void	Conversion::castInt(void)
{
	bool impossible = false;

	std::cout << "int: ";
	switch (_type)
	{
		case	Conversion::INT_TYPE:
		{
			char *endPtr = NULL;
			double inputResult = strtod(_str.c_str(), &endPtr);
			if ((errno == ERANGE && (inputResult == -HUGE_VAL || inputResult == HUGE_VAL))
				|| inputResult > std::numeric_limits<int>::max() || inputResult < std::numeric_limits<int>::min())
				throw std::exception();
			else
				_int = static_cast<int>(inputResult);
			break;
		}
		case Conversion::CHAR_TYPE:
			_int = _str[0];
			break;
		case Conversion::FLOAT_TYPE:
			if (_float > std::numeric_limits<int>::max() || _float < std::numeric_limits<int>::min())
				impossible = true;
			else
				_int = static_cast<int>(_float);
			break;
		case Conversion::DOUBLE_TYPE:
			if (_double > std::numeric_limits<int>::max() || _double < std::numeric_limits<int>::min())
				impossible = true;
			else
				_int = static_cast<int>(_double);
			break;
		default:
			impossible = true;
	}

	if (impossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int << std::endl;
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
