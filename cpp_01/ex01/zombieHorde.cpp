#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (nullptr);
	Zombie *zs = new Zombie[N];

	while (N--)
		zs[N].setName(name);
	return (zs);
}
