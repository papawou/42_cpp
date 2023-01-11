#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp(6);
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	sp.insert(v.begin(), v.end());
	std::cout << sp << std::endl;
	return (0);
}
