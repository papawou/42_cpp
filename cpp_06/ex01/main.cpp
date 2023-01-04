#include <sstream>
#include <iostream>
#include "main.hpp"

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int	main(int argc, char **argv)
{
	Data test;

	(void) argc;
	(void) argv;
	test.c = 'a';
	uintptr_t tmp = serialize(&test);
	Data *ptr_data = deserialize(tmp);

	std::cout << &test << ": " << test.c << std::endl;
	std::cout << tmp << std::endl;
	std::cout << ptr_data << ": " << ptr_data->c << std::endl;
	ptr_data->c = 'b';
	std::cout << ptr_data << ": " << ptr_data->c << std::endl;
	return (0);
}
