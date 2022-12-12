
#include "WrongCat.hpp"
#include <iostream>

void WrongCat::makeSound(void) const
{
	log("miaou");
}

void	WrongCat::log(std::string const &str) const
{
	std::cout << "WrongCat" << ": " << str << std::endl;
}

//Colpien
WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	log("constructor");
}

WrongCat::WrongCat(WrongCat const &wrongcat) : WrongAnimal(wrongcat)
{
	log("copy constructor");
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	log("operator=");
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void)
{
	log("destructor");
}
