#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	virtual void makeSound(void) const;

	Brain *getBrain(void) const;
//Colpien
	Cat(void);
	Cat(Cat const &);
	Cat &operator=(Cat const &);
	virtual ~Cat(void);
private:
	Brain *brain;
	void log(std::string const &str) const;
};

#endif