#include "FragTrap.hpp"
#include "main.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	log("constructor");
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(void) : ClapTrap()
{
	log("default constructor");
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &c) : ClapTrap(c)
{
	log("copy constructor");
}

FragTrap &FragTrap::operator=(FragTrap const &c)
{
	if (this != &c)
		ClapTrap::operator=(c);
	log("operator=");
	return (*this);
}

FragTrap::~FragTrap(void)
{
	log("destructor");
}

//METHODS
void FragTrap::highFivesGuys(void) const
{
	ft_putstr("high fives ?");
}

void FragTrap::log(std::string const &str) const
{
	ft_putstr("FragTrap " + _name + " " + str);
}