#ifndef	ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
public:
	unsigned int	size(void) const;

	Array<T>(unsigned int n);
//operator
	T& operator[](int idx);
	T	operator[](int idx) const;
//colpien
	Array<T>(void);
	Array<T>(Array<T> const &);
	Array<T> &operator=(Array<T> const &);
	virtual ~Array<T>(void);
private:
	unsigned int				_size;
	T					*_data;
};

#include "Array.tpp"

#endif