#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string const &name);
	HumanB(std::string const &name, Weapon const &weapon);

	//methods
	void	attack(void) const;
	
	//setters
	void	setWeapon(void);
	void	setWeapon(Weapon const &weapon);
private:
	std::string const name;
	Weapon const *weapon;
};

#endif