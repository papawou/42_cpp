#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float toFloat(void) const;
	int	toInt(void) const;

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

#endif