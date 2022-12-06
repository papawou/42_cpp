#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
public:
//constructors
	Weapon(std::string const &type);
//setters
	void setType(std::string const &type);
//getters
	std::string const &getType(void) const;
private:
	std::string type;
};

#endif