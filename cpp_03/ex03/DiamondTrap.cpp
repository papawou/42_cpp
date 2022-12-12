#include "main.hpp"
#include "DiamondTrap.hpp"

#include <string>
#include <iostream>

DiamondTrap::DiamondTrap(void) : ClapTrap((std::string)"defaultDiamond" + "_clap_name"), FragTrap(), ScavTrap()
{
	_name = "defaultDiamond";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
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