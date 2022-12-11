#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main(void)
{
	ClapTrap c;
	ScavTrap a;
	ScavTrap b;

	a = b;
	a.guardGate();
}