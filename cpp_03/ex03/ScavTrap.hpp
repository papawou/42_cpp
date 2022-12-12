#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public virtual ClapTrap
{
public:
	void guardGate(void) const;
	void attack(std::string const &target);

//
	ScavTrap(std::string name);
//colpien
	ScavTrap(void);
	ScavTrap(ScavTrap const &);
	virtual ~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &);
private:
	void log(std::string const &str) const;
};

#endif