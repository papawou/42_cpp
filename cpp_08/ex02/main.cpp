#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	srand(time(NULL));
	sp.addNumber(-10);
	sp.addNumber(-2);
	sp.addNumber(3);
	sp.addNumber(10);
	sp.addNumber(100);
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
	return (0);
}
