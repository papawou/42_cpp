#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	virtual void makeSound(void) const;

	Brain *getBrain(void) const;
//Colpien
	Dog(void);
	Dog(Dog const &);
	Dog &operator=(Dog const &);
	virtual ~Dog(void);
private:
	Brain *brain;
	void log(std::string const &str) const;
};

#endif