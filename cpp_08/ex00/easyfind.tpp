#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &cont, int i)
{
	typename T::iterator res = std::find(cont.begin(), cont.end(), i);
	if (res == cont.end())
		return cont.end();
	return res;
}

#endif