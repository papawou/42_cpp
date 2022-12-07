#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(std::string const &name) : name(name){}

void	Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void) const
{
	return (name);
}

void	Zombie::setName(std::string const &name)
{
	this->name = name;
}

Zombie::Zombie(void){}
Zombie::~Zombie(void)
{
	std::cout << name << " is dead" << std::endl;
}