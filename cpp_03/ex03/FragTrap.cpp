#include "FragTrap.hpp"
#include "main.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	log("constructor");
}

FragTrap::FragTrap(void) : ClapTrap("defaultFrag", 100, 100, 30)
{
	log("default constructor");
}

FragTrap::FragTrap(FragTrap const &c) : ClapTrap(c)
{
	log("copy constructor");
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
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
	log("high fives ?");
}

void FragTrap::log(std::string const &str) const
{
	ft_putstr("FragTrap " + _name + " " + str);
}