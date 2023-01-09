#include <exception>
#include <algorithm>
#include "Span.hpp"

void	Span::addNumber(int nb)
{
	if (_v.size() < _v.capacity())
		throw std::exception();
	_v.push_back(nb);
}

int	Span::shortestSpan(void) const
{
	unsigned int res = std::numeric_limits<unsigned int>::max();
	if (_v.size() < 2)
		throw std::exception();
	std::vector<int> sorted = _v;
	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::iterator it = sorted.begin(); it < sorted.end(); it++)
	{
		if (res > ((*it + 1) - (*it)))
		{
			
		}
	}
}

int	Span::longestSpan(void) const
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

Span::Span(void)
{
}
