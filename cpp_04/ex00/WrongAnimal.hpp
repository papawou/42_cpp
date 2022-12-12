#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
	void makeSound(void) const;
	std::string getType(void) const;
	
//Colpien
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const &animal);
	WrongAnimal &operator=(WrongAnimal const &rhs);
	virtual ~WrongAnimal(void);
protected:
	std::string type;
	WrongAnimal(std::string const &type);
private:
	void log(std::string const &str) const;
};

#endif