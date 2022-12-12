#include "main.hpp"
#include "DiamondTrap.hpp"

#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap((std::string)"defaultDiamond" + "_clap_name", 100, 50, 30), FragTrap(), ScavTrap()
{
	_name = "defaultDiamond";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name", 100, 50, 30), FragTrap(), ScavTrap(), _name(name)
{
}

DiamondTrap::DiamondTrap(DiamondTrap const &d) : ClapTrap(d), FragTrap(d), ScavTrap(d), _name(d._name)
{
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << _name << " + " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	log("destructor");
}

void DiamondTrap::log(std::string const &str) const
{
	ft_putstr("DiamondTrap " + _name + " " + str);
}