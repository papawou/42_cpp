#include "Weapon.hpp"

Weapon::Weapon(std::string const &type) : type(type){}

void	Weapon::setType(std::string const &type)
{
	this->type = type;
}

std::string const &Weapon::getType(void) const
{
	return (type);
}
