#include "Animal.hpp"
#include <iostream>

//public
void	Animal::makeSound(void) const
{
	log("make sound");
}

//private
void	Animal::log(std::string const &str) const
{
	std::cout << "Animal" << ": " << str << std::endl;
}

Animal::Animal(std::string const &type) : type(type)
{
	log("constructor(string)");
}
//Colpien
Animal::Animal(void) : type("Animal")
{
	log("default constructor");
}

Animal::Animal(Animal const &animal) : type(animal.type)
{
	log("copy constructor");
}

Animal &Animal::operator=(Animal const &rhs)
{
	log("operator=");
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	log("destructor");
}
