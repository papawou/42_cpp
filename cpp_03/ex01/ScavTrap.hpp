#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
public:
	void attack(std::string const &name);
	void guardGate(void);

	ScavTrap(std::string name);
//colpien
	ScavTrap(void);
	ScavTrap(ScavTrap const &);
	~ScavTrap(void);
	ScavTrap &operator=(ScavTrap const &);
private:
	void log(std::string const &str);
};

#endif