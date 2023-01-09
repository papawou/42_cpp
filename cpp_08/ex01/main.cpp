#include <iostream>
#include "Span.hpp"

int main()
{
	Span sp(10);
	std::vector<int> v(3);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	sp.insert(v.begin(), v.end());
	return (0);
}
