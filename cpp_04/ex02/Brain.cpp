#include "Brain.hpp"
#include <iostream>

void Brain::log(std::string const &str) const
{
	std::cout << "Brain: " << str << std::endl;
}

//Colpien
Brain::Brain(void)
{
	log("constructor");
}

Brain::Brain(Brain const &ref)
{
	log("copy constructor");
	for(int i = 0; i < 100; ++i)
		this->ideas[i] = ref.ideas[i];
}

Brain &Brain::operator=(Brain const &ref)
{
	log("operator=");
	for(int i = 0; i < 100; ++i)
		this->ideas[i] = ref.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	log("destructor");
}