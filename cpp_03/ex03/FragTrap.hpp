#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public virtual ClapTrap
{
public:
	void highFivesGuys(void) const;

//
	FragTrap(std::string name);
//colpien
	FragTrap(void);
	FragTrap(FragTrap const &);
	virtual ~FragTrap(void);
	FragTrap &operator=(FragTrap const &);
private:
	void log(std::string const &str) const;
};

#endif