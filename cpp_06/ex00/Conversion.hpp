#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <string>

class Conversion
{
public:
	enum e_type
	{
		NO_TYPE,
		CHAR_TYPE,
		INT_TYPE,	
		FLOAT_TYPE,
		DOUBLE_TYPE,
		MINF_TYPE,
		INF_TYPE,
		MINFF_TYPE,
		INFF_TYPE,
		NAN_TYPE,
		NANF_TYPE
	};

	Conversion(std::string const &);
	Conversion(Conversion const &);
	~Conversion(void);
	Conversion &operator=(Conversion const &);
private:
	std::string const _str;
	e_type	_type;
	char	_char;
	int	_int;
	float	_float;
	double	_double;

	e_type	checkType(void) const;
	void	castType(void);

	void	castInt(void);
	void	castDouble(void);
	void	castFloat(void);
	void	castChar(void);

	Conversion(void);
};

#endif