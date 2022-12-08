#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>

class Fixed
{
public:
	static Fixed	min(Fixed const &lhs, Fixed const &rhs);
	static Fixed	min(Fixed &lhs, Fixed &rhs);
	static Fixed	max(Fixed const &lhs, Fixed const &rhs);
	static Fixed	max(Fixed &lhs, Fixed &rhs);

//get
	int	getRawBits(void) const;
//set
	void	setRawBits(int const raw);

//methods
	float toFloat(void) const;
	int	toInt(void) const;

//operator
	bool	operator>(Fixed const &) const;
	bool	operator<(Fixed const &) const;
	bool	operator==(Fixed const &) const;
	bool	operator!=(Fixed const &) const;
	bool	operator>=(Fixed const &) const;
	bool	operator<=(Fixed const &) const;
//operator + - * /
	Fixed	const operator+(Fixed const &) const;
	Fixed	const operator-(Fixed const &) const;
	Fixed const	operator*(Fixed const &) const;
	Fixed const	operator/(Fixed const &) const;
	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed	operator--(int);

//constructors
	Fixed(int const nb);
	Fixed(float const nb);
//colpien
	Fixed(void);
	Fixed(Fixed const &);
	~Fixed(void);
	Fixed &operator=(Fixed const &);
private:
	static int const f_bits = 8;

	int nb;
};

std::ostream& operator<<(std::ostream &os, Fixed const &f);

#endif