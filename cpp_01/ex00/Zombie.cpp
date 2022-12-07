#include "Zombie.hpp"

#include <iostream>

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is dead" << std::endl;
}

Zombie::Zombie(std::string name) : name(name){}
