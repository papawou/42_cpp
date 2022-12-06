#include "HumanA.hpp"

#include <iostream>

HumanA::HumanA(std::string const &name, Weapon const &weapon) : name(name), weapon(weapon){};

void HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
