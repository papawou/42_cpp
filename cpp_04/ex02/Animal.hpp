#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal
{
public:
	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
//Colpien
	Animal(void);
	Animal(Animal const &animal);
	Animal &operator=(Animal const &rhs);
	virtual ~Animal(void);
protected:
	std::string type;
	Animal(std::string const &type);
private:
	void log(std::string const &str) const;
};

#endif