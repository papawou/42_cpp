#include "Dog.hpp"
#include <iostream>

void Dog::makeSound(void) const
{
	log("waouf");
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}

void	Dog::log(std::string const &str) const
{
	std::cout << "Dog" << ": " << str << std::endl;
}

//Colpien
Dog::Dog(void) : Animal("Dog"), brain(new Brain())
{
	log("constructor");
}

Dog::Dog(Dog const &dog) : Animal(dog), brain(new Brain(*dog.brain))
{
	log("copy constructor");
}

Dog &Dog::operator=(Dog const &rhs)
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

Dog::~Dog(void)
{
	log("destructor");
	delete brain;
}
