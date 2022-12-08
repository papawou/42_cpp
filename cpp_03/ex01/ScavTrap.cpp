#include "ScavTrap.hpp"
#include "main.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	log("constructor");
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
	log("default constructor");
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const &c) : ClapTrap(c)
{
	log("copy constructor");
}

ScavTrap &ScavTrap::operator=(ScavTrap const &c)
{
	ClapTrap::operator=(c);
	log("operator=");
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	log("destructor");
}

//METHODS
void ScavTrap::guardGate(void)
{
	log("mode Gate keeper enabled");
}

void ScavTrap::log(std::string const &str)
{
	ft_putstr("ScavTrap " + _name + " " + str);
}