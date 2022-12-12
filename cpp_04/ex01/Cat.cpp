#include "Cat.hpp"
#include <iostream>

void Cat::makeSound(void) const
{
	log("miaou");
}

void	Cat::log(std::string const &str) const
{
	std::cout << "Cat" << ": " << str << std::endl;
}

//Colpien
Cat::Cat(void) : Animal("Cat"), brain(new Brain())
{
	log("constructor");
}

Cat::Cat(Cat const &cat) : Animal(cat), brain(new Brain(*cat.brain))
{
	log("copy constructor");
}

Cat &Cat::operator=(Cat const &rhs)
{
	log("operator=");
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete this->brain;
		this->brain = new Brain(*rhs.brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	log("destructor");
	delete brain;
}
