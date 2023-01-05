#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename U>
void	iter(T *tab, std::size_t len, void (*func)(U elem))
{
	for (std::size_t i = 0; i < len; i++)
		func(tab[i]);
}

template<typename T>
void show(T elem)
{
	std::cout << elem << std::endl;
}

#endif