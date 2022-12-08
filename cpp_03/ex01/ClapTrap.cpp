#include "ClapTrap.hpp"
#include <string>
#include <iostream>
#include "main.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	log("constructor");
}

//colpien
ClapTrap::ClapTrap(void) : _hit_points(10), _energy_points(10), _attack_damage(0)
{
	log("default constructor");
}

ClapTrap::ClapTrap(ClapTrap const &c) : _name(c._name), _hit_points(c._hit_points), _energy_points(c._energy_points), _attack_damage(c._attack_damage)
{
	log("copy constructor");
}

ClapTrap& ClapTrap::ClapTrap::operator=(ClapTrap const &c)
{
	log("operator=");
	this->_name = c._name;
	this->_hit_points = c._hit_points;
	this->_energy_points = c._energy_points;
	this->_attack_damage = c._attack_damage;
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

//private
void ClapTrap::log(std::string const &str)
{
	ft_putstr("ClapTrap " + _name + " " + str);
}
