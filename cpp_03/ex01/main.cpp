#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap test("PLOP");

	test.attack("DUMMY");
	test.beRepaired(42);
	test.takeDamage(42);
	test.takeDamage(42);
}