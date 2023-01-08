#include "easyfind.hpp"

#include <vector>
#include <iostream>

int	main(void)
{
	int arr[] = {1, 2, 3};
	std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
	std::vector<int>::iterator nb = easyfind(v, 1);
	std::cout << *nb << std::endl;
	std::vector<int>::iterator nb_tmp = easyfind(v, 42);
	std::vector<int>::iterator nb_end = v.end();
	std::cout << &nb_tmp << " : " << &nb_end << std::endl;
}
