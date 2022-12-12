#include "Dog.hpp"
#include <iostream>

void Dog::makeSound(void) const
{
	log("waouf");
}

void	Dog::log(std::string const &str) const
{
	std::cout << "Dog" << ": " << str << std::endl;
}

//Colpien
Dog::Dog(void) : Animal("Dog")
{
	log("constructor");
}

Dog::Dog(Dog const &dog) : Animal(dog)
{
	log("copy constructor");
}

Dog &Dog::operator=(Dog const &rhs)
{
	log("operator=");
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	log("destructor");
}
