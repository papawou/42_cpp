#include <iostream>
#include "Span.hpp"

int main(void)
{
	try	{
		Span sp = Span(5);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "sp" << std::endl;
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		std::cout << std::endl;
		Span sp2 = Span(10);
		srand(time(NULL));
		for(int i = 0; i < 10; i++)
		{
			sp2.addNumber(rand() % 10);
		}
		std::cout << "sp2 " << sp2.size() << std::endl;
		std::cout << sp2 << std::endl;
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		std::cout << "---Test exception---" << std::endl;
		sp2.addNumber(25);
	}
	catch (std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}
	return 0;
}
