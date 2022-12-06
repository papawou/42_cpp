#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <string>

class Zombie
{
public:
	Zombie(std::string const &name);
	
	//getters
	std::string getName(void) const;
	//setters
	void	setName(std::string const &name);

	//methods
	void announce(void) const;
	
	//colpien
	Zombie(void);
	~Zombie(void);
private:
	std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif