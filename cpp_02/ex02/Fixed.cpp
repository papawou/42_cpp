#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//static
Fixed Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs > rhs)
		return rhs;
	return lhs;
}

Fixed Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return rhs;
	return lhs;
}

Fixed	Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

Fixed	Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (rhs);
	return (lhs);
}

//methods
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return nb;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	nb = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)nb / (1 << Fixed::f_bits));
}

int	Fixed::toInt(void) const
{
	return (nb >> Fixed::f_bits);
}

//constructors
Fixed::Fixed(float const nb) : nb(roundf(nb * (1 << Fixed::f_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int const nb) : nb(nb << Fixed::f_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

//affichage
std::ostream& operator<<(std::ostream &os, Fixed const &rhs)
{
	os << rhs.toFloat();
	return (os);
}

//operators > < == <= => !=
bool	Fixed::operator>(Fixed const &rhs) const
{
	return (nb > rhs.nb);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return !(*this > rhs);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (nb == rhs.nb);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return !(*this == rhs);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (*this > rhs || *this == rhs);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (*this < rhs || *this == rhs);
}

//operators + - * /
Fixed	const Fixed::operator+(Fixed const &rhs) const
{
	Fixed ret;
	ret.nb = nb + rhs.nb;
	return ret;
}

Fixed	const Fixed::operator-(Fixed const &rhs) const
{
	Fixed ret;
	ret.nb = nb - rhs.nb;
	return ret;
}

Fixed const	Fixed::operator*(Fixed const &rhs) const
{
	Fixed ret;
	ret.nb = (this->nb * rhs.nb) / (1 << Fixed::f_bits);
	return ret;
}

Fixed const	Fixed::operator/(Fixed const &rhs) const
{
	Fixed ret;
	ret.nb = (this->nb * (1 << Fixed::f_bits)) / rhs.nb;
	return ret;
}

Fixed& Fixed::operator++(void)
{
	++nb;
	return (*this);
}

Fixed Fixed::operator++(int a)
{
	(void) a;
	Fixed ret(*this);
	operator++();
	return (ret);
}

Fixed& Fixed::operator--(void)
{
	--nb;
	return (*this);
}

Fixed	Fixed::operator--(int a)
{
	(void) a;
	Fixed ret(*this);
	operator--();
	return (ret);
}

//Colpien
Fixed::Fixed(void) : nb(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &f) : nb(f.nb)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->nb = rhs.nb;
	return (*this);
}