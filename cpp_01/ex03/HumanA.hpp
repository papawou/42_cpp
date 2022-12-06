#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string const &name, Weapon const &weapon);

	void	attack(void) const;
private:
	std::string const name;
	Weapon const &weapon;
};

#endif