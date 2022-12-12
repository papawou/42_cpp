#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	virtual void makeSound(void) const;
//Colpien
	WrongCat(void);
	WrongCat(WrongCat const &);
	WrongCat &operator=(WrongCat const &);
	virtual ~WrongCat(void);
private:
	void log(std::string const &str) const;
};

#endif