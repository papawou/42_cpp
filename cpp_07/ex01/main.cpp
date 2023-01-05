#include <iostream>
#include "iter.hpp"

void	incr(int &elem)
{
	++elem;
}

int main( void )
{
	int tab[5] = {0, 1, 2, 3, 4};
	iter<int, int&>(tab, 5, &incr);
	iter<int>(tab, 5, &show<int>);
	return 0;
}
