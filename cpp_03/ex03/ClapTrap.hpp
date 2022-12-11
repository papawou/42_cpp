#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class ClapTrap
{
public:
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap(std::string name);
//colpien
	ClapTrap(void);
	ClapTrap(ClapTrap const &);
	ClapTrap& operator=(ClapTrap const &);
	virtual ~ClapTrap(void);
protected:
	std::string _name;
	int	_hit_points;
	int _energy_points;
	int _attack_damage;

	ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage);
private:
	void log(std::string const &str) const;
};

#endif