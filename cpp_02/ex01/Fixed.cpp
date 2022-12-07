#include "Fixed.hpp"
#include <iostream>
#include <cmath>

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

Fixed::Fixed(float const nb) : nb(roundf(nb * (1 << Fixed::f_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int const nb) : nb(nb << Fixed::f_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &os, Fixed const &f)
{
	os << f.toFloat();
	return (os);
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
Fixed &Fixed::operator=(Fixed const &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->nb = f.nb;
	return (*this);
}