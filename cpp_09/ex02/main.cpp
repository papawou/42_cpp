#include <vector>
#include <list>
#include <iostream>

#include "PmergeMe.hpp"

void kperror(std::string const &str)
{
	std::cout << "Error: " << str << std::endl;
}

int main(int argc, char *argv[])
{
	std::vector<int> v;
	std::list<int> l;
	double time_elapsed;

	if (argc != 2)
	{
		kperror("Expected an argument");
		return (1);
	}

	try
	{
		time_elapsed = PmergeMe<std::vector<int> >::bench(v, argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	PmergeMe<std::vector<int> >::print_bench(v, "vector", time_elapsed);

	try
	{
		time_elapsed = PmergeMe<std::list<int> >::bench(l, argv[1]);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	PmergeMe<std::list<int> >::print_bench(l, "list", time_elapsed);
	return (0);
}