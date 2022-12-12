#include "Cat.hpp"
#include <iostream>

void Cat::makeSound(void) const
{
	log("waouf");
}

void	Cat::log(std::string const &str) const
{
	std::cout << "Cat" << ": " << str << std::endl;
}

//Colpien
Cat::Cat(void) : Animal("Cat")
{
	log("constructor");
}

Cat::Cat(Cat const &cat) : Animal(cat)
{
	log("copy constructor");
}

Cat &Cat::operator=(Cat const &rhs)
{
	log("operator=");
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

Cat::~Cat(void)
{
	log("destructor");
}
