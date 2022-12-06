#include "Zombie.hpp"

int main(void)
{
	Zombie * z_ptr = newZombie("z_ptr");
	randomChump("randomchump");

	z_ptr->announce();
	delete z_ptr;
	return (0);
}
