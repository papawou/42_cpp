#include "WrongAnimal.hpp"
#include <iostream>

//public
void	WrongAnimal::makeSound(void) const
{
	log("make sound");
}

//protected
std::string WrongAnimal::getType(void) const
{
	return type;
}

//private
void	WrongAnimal::log(std::string const &str) const
{
	std::cout << "WrongAnimal" << ": " << str << std::endl;
}

WrongAnimal::WrongAnimal(std::string const &type) : type(type)
{
	log("constructor(string)");
}
//Colpien
WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	log("default constructor");
}

WrongAnimal::WrongAnimal(WrongAnimal const &wronganimal) : type(wronganimal.type)
{
	log("copy constructor");
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	log("operator=");
	if (this != &rhs)
		type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	log("destructor");
}
