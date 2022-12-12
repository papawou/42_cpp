#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	using ScavTrap::attack;
	void whoAmI(void) const;

	DiamondTrap(std::string name);
//colpien
	DiamondTrap(void);
	DiamondTrap(DiamondTrap const &);
	DiamondTrap& operator=(DiamondTrap const &);
	virtual ~DiamondTrap(void);
private:
	std::string _name;
	void log(std::string const &str) const;
};

#endif