#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <string>

class Conversion
{
public:
	enum e_type
	{
		CHAR_TYPE,
		INT_TYPE,	
		FLOAT_TYPE,
		DOUBLE_TYPE,
		MINF_TYPE,
		INF_TYPE,
		NAN_TYPE,
		NO_TYPE
	};

	void	castType(void);
	Conversion(std::string const &);
	Conversion(Conversion const &);
	~Conversion(void);
private:
	std::string const _str;
	e_type	_type;
	char	_char;
	int	_int;
	float	_float;
	double	_double;

	e_type	checkType(void) const;
	void	castInt(void);
	void	castDouble(void);
	void	castFloat(void);
	void	castChar(void);

	Conversion(void);
	Conversion &operator=(Conversion const &);
};

#endif