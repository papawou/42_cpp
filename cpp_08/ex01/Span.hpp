#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>

class Span
{
public:
	void addNumber(int nb);
	int	shortestSpan(void) const;
	int	longestSpan(void) const;

	Span(unsigned int n);
	//colpien
	Span(const Span &);
	Span &operator=(const Span &);
	virtual ~Span(void);
private:
	std::vector<int> _v;

	Span(void);
};

#endif