#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	virtual void makeSound(void) const;
//Colpien
	Cat(void);
	Cat(Cat const &);
	Cat &operator=(Cat const &);
	virtual ~Cat(void);
protected:
	void log(std::string const &str) const;
};

#endif