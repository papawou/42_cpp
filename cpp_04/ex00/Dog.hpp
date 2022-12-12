#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	virtual void makeSound(void) const;
//Colpien
	Dog(void);
	Dog(Dog const &);
	Dog &operator=(Dog const &);
	virtual ~Dog(void);
protected:
	void log(std::string const &str) const;
};

#endif