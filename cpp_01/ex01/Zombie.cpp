#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string const &name) : _name(name){}

void	Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void) const
{
	return (_name);
}

void	Zombie::setName(std::string const &name)
{
	_name = name;
}

Zombie::Zombie(void){}
Zombie::~Zombie(void)
{
	std::cout << _name << " is dead" << std::endl;
}