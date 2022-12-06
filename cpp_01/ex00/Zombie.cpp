#include "Zombie.hpp"

#include <iostream>

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name){}
