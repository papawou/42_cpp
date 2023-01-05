#include <iostream>
#include "Array.hpp"

int	main(void)
{
	Array<float> arr(10);
	Array<float> arr2(10);

	arr = arr2;
}