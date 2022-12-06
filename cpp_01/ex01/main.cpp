#include "Zombie.hpp"

int	main(void)
{
	int n = 5;

	Zombie* zs = zombieHorde(n, "TestZ");
	if (zs == nullptr)
		return (1);
	while (n--)
		zs[n].announce();
	delete [] zs;
	return (0);
}
