#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(ShrubberyCreationForm const &);
	virtual ~ShrubberyCreationForm(void);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &);

private:
	ShrubberyCreationForm(void);
	void	execute_action(void) const;
};

#endif