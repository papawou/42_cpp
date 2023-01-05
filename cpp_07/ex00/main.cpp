#include <iostream>
#include "whatever.hpp"

int main(void)
{
	int a = 0;
	int b = 1;

	std::cout << "max: " << max<int>(a, b) << std::endl;
	std::cout << "min: " << min<int>(a, b) << std::endl;
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "swap" << std::endl;
	swap<int>(&a, &b);
	std::cout << "a: " << a << ", b: " << b << std::endl;
}
