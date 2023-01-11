#include <exception>
#include <algorithm>
#include <iostream>
#include "Span.hpp"

void	Span::addNumber(int nb)
{
	if (_v.size() > _v.capacity())
		throw std::exception();
	_v.push_back(nb);
}

size_t	Span::size(void) const
{
	return _v.size();
}

void	Span::insert(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (((end - start) + _v.size()) > _v.capacity())
		throw std::exception();
	_v.insert(_v.end(), start, end);
}

unsigned int	Span::shortestSpan(void) const
{
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());
	unsigned int res = sorted[1] - sorted[0];
	for (std::vector<int>::iterator it = sorted.begin() + 1; it < (sorted.end() - 1); it++)
		if (res > (unsigned int)(*(it + 1) - (*it)))
			res = (*(it + 1) - (*it));
	return (res);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_v.size() < 2)
		throw std::exception();
	return (*std::max_element(std::begin(_v), std::end(_v)) - *std::min_element(std::begin(_v), std::end(_v)));
}

Span::Span(unsigned int n)
{
	_v.reserve(n);
}

Span::Span(const Span & sp)
{
	*this = sp;
}

Span &Span::operator=(const Span & rhs)
{
	if (this == &rhs)
	{
		this->_v.clear();
		this->_v.reserve(rhs._v.capacity());
		this->_v = rhs._v;
	}
	return (*this);
}

int &Span::operator[](size_t index)
{
	if (index < _v.size())
		return _v[index];
	throw std::exception();
}

int const &Span::operator[](size_t index) const
{
	if (index < _v.size())
		return _v[index];
	throw std::exception();
}

Span::Span(void)
{
}

Span::~Span(void)
{
}

std::ostream &operator<<(std::ostream &os, Span const &sp)
{
	for(size_t i = 0; i < sp.size(); i++)
	{
		os << sp[i] << ", ";
		os << std::endl;
	}
	return (os);
}
