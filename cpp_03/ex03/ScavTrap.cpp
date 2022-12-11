#include "ScavTrap.hpp"
#include "main.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	log("constructor");
}

ScavTrap::ScavTrap(void) : ClapTrap("defaultScav", 100, 50, 20)
{
	log("default constructor");
}

ScavTrap::ScavTrap(ScavTrap const &c) : ClapTrap(c)
{
	log("copy constructor");
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	log("operator=");
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	log("destructor");
}

//METHODS
void ScavTrap::attack(std::string const &target)
{
	if (_energy_points == 0)
	{
		log("out of energy for attack");
		return ;
	}
	log("attacks " + target + ", causing " + ft_itoa(_attack_damage) + " points of damage!");
	--_energy_points;
}

void ScavTrap::guardGate(void) const
{
	log("mode Gate keeper enabled");
}

void ScavTrap::log(std::string const &str) const
{
	ft_putstr("ScavTrap " + _name + " " + str);
}