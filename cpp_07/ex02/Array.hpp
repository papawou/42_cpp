#ifndef	ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
public:
	unsigned int	size(void) const;

	Array<T>(unsigned int n);
//operator
	T& operator[](unsigned int idx);
	T	operator[](unsigned int idx) const;
//colpien
	Array<T>(void);
	Array<T>(Array<T> const &);
	Array<T> &operator=(Array<T> const &);
	virtual ~Array<T>(void);
private:
	unsigned int				_size;
	T					*_data;
};

template<typename T>
std::ostream& operator<<(std::ostream &os, Array<T>& rhs)
{
	for(unsigned int i = 0; i < rhs.size(); i++)
		os << rhs[i] << ", ";
	return (os);
}

#include "Array.tpp"

#endif