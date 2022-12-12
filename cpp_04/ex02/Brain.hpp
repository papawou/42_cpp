#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
public:
	std::string ideas[100];

//Colpien
	Brain(void);
	Brain(Brain const &);
	Brain &operator=(Brain const &);
	~Brain(void);
private:
	void log(std::string const &str) const;
};

#endif