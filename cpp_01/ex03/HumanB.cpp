#include "HumanB.hpp"

#include <iostream>

HumanB::HumanB(std::string const &name) : name(name), weapon(nullptr){}
HumanB::HumanB(std::string const &name, Weapon const &weapon) : name(name), weapon(&weapon){}

void HumanB::attack(void) const
{
	if (weapon == nullptr)
	{
		std::cout << name << " attacks with their fingers" << std::endl;
		return ;
	}
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(void)
{
	weapon = nullptr;
}

void	HumanB::setWeapon(Weapon const &weapon)
{
	this->weapon = &weapon;
}
