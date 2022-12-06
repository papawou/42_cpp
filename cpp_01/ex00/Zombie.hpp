#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <string>

class Zombie
{
public:
	Zombie(std::string name);
	
	void announce(void) const;
	std::string const getName(void) const;
	
	~Zombie(void);
private:
	std::string _name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif