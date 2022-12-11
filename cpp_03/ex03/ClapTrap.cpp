#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include "main.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	log("constructor");
}

//Colpien
ClapTrap::ClapTrap(void) : _name("defaultClap"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	log("default constructor");
}

ClapTrap::ClapTrap(ClapTrap const &c) : _name(c._name), _hit_points(c._hit_points), _energy_points(c._energy_points), _attack_damage(c._attack_damage)
{
	log("copy constructor");
}

ClapTrap& ClapTrap::ClapTrap::operator=(ClapTrap const &rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hit_points = rhs._hit_points;
		_energy_points = rhs._energy_points;
		_attack_damage = rhs._attack_damage;
	}
	log("operator=");
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	log("destructor");
}

//METHODS
void ClapTrap::attack(std::string const &target)
{
	if (_energy_points == 0)
	{
		log("out of energy for attack");
		return ;
	}
	log("attacks " + target + ", causing " + ft_itoa(_attack_damage) + " points of damage!");
	--_energy_points;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	log("receives " + ft_itoa(_hit_points) + "-" + ft_itoa(amount) + " points of damage");
	if (_hit_points <= (int)amount)
	{
		_hit_points = 0;
		log("is dead");
	}
	else
		_hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points == 0)
	{
		log("out of energy for repair");
		return ;
	}
	log("repairs " + ft_itoa(_hit_points) + "+" + ft_itoa(amount));
	_hit_points += amount;
}

//protected
ClapTrap::ClapTrap(std::string name, int hit_points, int energy_points, int attack_damage) : _name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage){}

//private
void ClapTrap::log(std::string const &str) const
{
	ft_putstr("ClapTrap " + _name + " " + str);
}
